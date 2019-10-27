#!/bin/bash


#path to test data
TEST_DATA=./tests

# iterate i: 0 1 2 ... 100
for i in $(seq 0 100) ; do
  if [ ! -e $TEST_DATA/${i}_in.txt ] ; then
    # no more input files
    echo "Done"
    #exit 0
  fi

  echo -n "Test $i: "
  ./a.out < $TEST_DATA/${i}_in.txt > data.out
  if [ $? -gt 64 ] ; then
    # segmentation fault or a similar problem
    exit 1
  fi

  if ! diff $TEST_DATA/${i}_out.txt data.out ; then
    # output mismatch
    echo "Test $TEST_DATA/$i.txt failed";
    exit 1
  fi
  echo "OK";
done