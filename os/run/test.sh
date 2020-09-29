#!/bin/bash
tap0_exit=`ifconfig | grep tap1`

if [ ! -n "$tap0_exit" ]; then
	  
	echo "IS NULL"
	  
else
	  
	echo "NOT NULL"
	  
fi

