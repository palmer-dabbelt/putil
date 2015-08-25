set -ex

tempdir=`mktemp -d -t ptest.XXXXXXXXXX`
trap "rm -rf $tempdir" EXIT
cd $tempdir

touch lock

flock --shared lock sleep 5s &
sleep 1s

start="$(date +%s)"
$PTEST_BINARY lock
stop="$(date +%s)"

if [[ "$(((stop - start)))" > 3 ]]
then
    exit 1
else
    exit 0
fi
