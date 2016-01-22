#include "tempdir.bash"

cat >input <<EOF
2.200000
3.002300
EOF

cat >output <<EOF
2.200000
3.002300
0.000000
0.000000
0.000000
0.000000
0.000000
0.000000
0.000000
0.000000
0.000000
0.000000
EOF

#include "harness.bash"
