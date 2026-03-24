commit 597bc485d6906359ad667fc8ead5e5f0ede03a0a
Author: Jens Axboe <axboe@kernel.dk>
Date:   Tue Apr 24 21:23:53 2007 +0200

    cfq-iosched: speedup cic rb lookup
    
    We often lookup the same queue many times in succession, so cache
    the last looked up queue to avoid browsing the rbtree.
    
    Signed-off-by: Jens Axboe <jens.axboe@oracle.com>

diff --git a/block/cfq-iosched.c b/block/cfq-iosched.c
index 94f53a1f4677..64df3fa303b0 100644
--- a/block/cfq-iosched.c
+++ b/block/cfq-iosched.c
@@ -1165,6 +1165,8 @@ static void cfq_free_io_context(struct io_context *ioc)

 	struct rb_node *n;
 	int freed = 0;
 
+	ioc->ioc_data = NULL;
+
 	while ((n = rb_first(&ioc->cic_root)) != NULL) {
 		__cic = rb_entry(n, struct cfq_io_context, rb_node);
 		rb_erase(&__cic->rb_node, &ioc->cic_root);
@@ -1228,10 +1230,11 @@ static void cfq_exit_io_context(struct io_context *ioc)
 	struct cfq_io_context *__cic;
 	struct rb_node *n;
 
+	ioc->ioc_data = NULL;
+
 	/*
 	 * put the reference this task is holding to the various queues
 	 */
-
 	n = rb_first(&ioc->cic_root);
 	while (n != NULL) {
 		__cic = rb_entry(n, struct cfq_io_context, rb_node);
@@ -1415,6 +1418,10 @@ static void
 cfq_drop_dead_cic(struct io_context *ioc, struct cfq_io_context *cic)
 {
 	WARN_ON(!list_empty(&cic->queue_list));
+
+	if (ioc->ioc_data == cic)
+		ioc->ioc_data = NULL;
+
 	rb_erase(&cic->rb_node, &ioc->cic_root);
 	kmem_cache_free(cfq_ioc_pool, cic);
 	elv_ioc_count_dec(ioc_count);
@@ -1430,6 +1437,13 @@ cfq_cic_rb_lookup(struct cfq_data *cfqd, struct io_context *ioc)
 	if (unlikely(!ioc))
 		return NULL;
 
+	/*
+	 * we maintain a last-hit cache, to avoid browsing over the tree
+	 */
+	cic = ioc->ioc_data;
+	if (cic && cic->key == cfqd)
+		return cic;
+
 restart:
 	n = ioc->cic_root.rb_node;
 	while (n) {
@@ -1445,8 +1459,10 @@ cfq_cic_rb_lookup(struct cfq_data *cfqd, struct io_context *ioc)
 			n = n->rb_left;
 		else if (key > k)
 			n = n->rb_right;
-		else
+		else {
+			ioc->ioc_data = cic;
 			return cic;
+		}
 	}
 
 	return NULL;
