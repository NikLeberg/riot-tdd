# First compile all tests
./make_for_each_dir.sh all

# Register cleanup of capture output at script exit
trap "rm embunit_output.txt" EXIT

# Start native terminal and capture output
./make_for_each_dir.sh term | tee embunit_output.txt

# Check output of tests.
# "This is RIOT!" should be in the output otherwise no tests ran.
# If a test failed there will be "run X failures Y" printed in the summary.
test $(grep -c "This is RIOT!" embunit_output.txt) -gt 1
test $(grep -c "failures" embunit_output.txt) -eq 0
