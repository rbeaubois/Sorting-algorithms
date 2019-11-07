# File versioning

v0 : Radix sort using digits (modulo)
v1 : Radix sort using bits (bytes or nibbles)
v2 : v1 plus openmp
v3 : v1 with switch between 2 arrays (FASTEST)
v4 : v3 for systemC 

# Running
cd vX/
make
./bin/"target" (else data path is wrong)
