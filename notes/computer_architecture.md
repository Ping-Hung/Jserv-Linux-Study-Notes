# Vocabulary
## Locality
**Principle**: program likely to access a relatively small portion of the
address space at any instance of time.

### Temporal Locality:
- Memory that has been accessed once are more likely to be accessed in next
  iteration/cycle.
- Keep **most recently acccessed** data items closer to the processor.

### Spatial Locality
- Locations around _data that has been accessed_ are more likely to be accessed
- Move blocks consisting of **contiguous words** to the upper levels.
