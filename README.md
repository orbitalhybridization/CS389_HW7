# HW7: micro optimization
Ian Jackson

## Machine & Compiler Information
CPU: Intel(R) Core(TM) i5-2467M CPU @ 1.60GHz__
RAM Capacity: 2 GB__
OS: Ubuntu 18.04__
gcc version: 7.5.0__

	
## Part 1: Naive implementation
Running the atoi code off the bat gave me a run time of *0.079s*.__ 
I chose to use sscanf from C's standard template library just to observe 
the performance difference, replacing the conversion line with:
`	sscanf(lines[i],"%u",&nums[i]);
`, which I tried to optimize by changing the %u for unsigned int to the
SCNu32 macro for unsigned int_32 type from inttypes.h. This resulted in a run time of sscanf: *0.412s*,
and the type specification didn't change it much.__

Looking into this almost six-fold increase in run time, sscanf, I found, is notoriously slow compared
to atoi. This is possibly due to the error-checking that comes with sscanf, which atoi doesn't have
(a great feature, but not what we're looking for given the assumptions about our data).__

After this naive implementation, it's time to identify how to optimize it.

## Part 2: Optimized implementation

In order to identify where to optimize, I ran perf top to see how much of the system performance was being taken up by
the driver, and it appeared that checksum and convert_all were using roughly the same percentage (~6-7%). It also seemed
that the strtok allocation loop was using a huge percentage of memory, which made sense, but I was committed to not touching the driver.__

It was at this point when I read that we weren't allowed to look anything up, so I scratched my naive implementation work (because I found it by  looking up the standard library's string-to-int conversion functions) and tried a character-by-character approach for each line. I apologize for having not read the instructions carefully, and I understand any points that need to be taken away for having done so, but this new implementation attempts to return to the guidelines of the assignment. The new implementation worked somewhat, but I was having issues copying over the string into an int. My code would read -- for example -- a string "2" as an int "50." It was at this point that I decided to cut my losses and turn in what I had. :-)
