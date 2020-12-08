### Task 8.5: TCP header (20 pts)

**Objective:** Practice binary operations.

Low layer communication protocols aim to utilize the available space
in communication efficiently, to reduce the amount of needed network traffic.
We will take a look at the TCP protocol as an example of this.

You can find information about the TCP protocol and TCP header 
[here](https://en.wikipedia.org/wiki/Transmission_Control_Protocol#TCP_segment_structure).
To implement this task, you will need information about the structure of the
TCP header, as described in the wikipedia page linked above.

You can read the TCP header diagram as follows: each row in the diagram
represents 4 bytes (32 bits) in the header. The byte count is shown on
the top of the diagram, and on the left side of the diagram, and by adding
these together you will what is the byte offset from the beginning of the
packet for the particular header field. For example, the *checksum* field
can be found at 16th and 17th byte. If you think the TCP header as a byte
array, you will find the *checksum* field at `tcp_hdr[16]` and `tcp_hdr[17]`.

**Additional tips:**

  * Pay attention to the [precedence](http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Operator_precedence)
  of C operators regarding the binary
  operations. The bit shift operators `<<` and `>>` are evaluated before
  arithmetic operatos (such as '+' and '-'). Use parentheses as needed.


a) Parse header
------------------

Implement the following functions that each read and return one field from
the TCP header. In order to parse the fields, you will need to find the
respective bits in the TCP header, and leverage bitwise operations to represent
the value as a single integer return parameter.

All functions get the pointer to the beginning of TCP header as a parameter.

  * `getSourcePort` returns the source port. This is a 16-bit value, but you will
  need to process each byte separately. I.e.: if header[0] is 0xac, and header[1] is 0xde,
  you will need to return integer 0xacde. For this you will need to apply
  bitwise operations.
  
  * `getDestinationPort` returns the destination port. The same note applies here
  as above regarding handling of 16-bit values.

  * `getAckFlag` returns the value of ACK flag (either 0 or 1). N.B. ACK is in byte 13.

  * `getDataOffset` returns the length of the header (i.e., the data offset)
	

b) Write header
----------------

Implement the following functions to produce parts of a TCP header. Each
function gets an integer value as a parameter, that should be placed in right
location in TCP header.

  * `setSourcePort` that sets the source port field in TCP header as indicated in the *port* parameter.
  You will need to handle each byte separately: the most significant eight bits
  are placed at header[0], and least significant eight bits at header[1].

  * `setDestinationPort` that sets the destination port field as indicated in
  the *port* parameter. The byte order is as described above.

  * `setAckFlag` that sets the ACK bit on or off depending on whether the
  function argument is 0 (off) or non-zero (on).

  * `setDataOffset` that sets the data offset field.

In each function, only the given TCP header field can change, and all other
parts of the header must remain unchanged.
