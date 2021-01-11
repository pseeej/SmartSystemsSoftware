
if [[ $# -lt 1 ]]; then
	echo "Usage ./.sh vaccl"
	exit
fi

PROG=$1

gcc -pg "$PROG".c -o $PROG
./$PROG
gprof $PROG > $PROG.gprof
cat $PROG.gprof
