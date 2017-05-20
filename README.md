# gb_popen
Multi-pipe popen implementation (don't cross the streams!)

The driver program shows how to use. Note that technically, only one of the pipes needs to be closed after the streams are read.

This implementation is not known to be threadsafe and the author retains no liability from any expectations otherwise. Please see license.

gb_popen() takes a command and two file descriptors (by reference) opening streams for stdout and stderr independently.
