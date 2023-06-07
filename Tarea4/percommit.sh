#!/bin/bash

#Run Flake8 on staged files
git diff --cached --name-only --diff-filter=AM | grep '.py$' | xargs flake8 

#If Flake8 found errors, exit with a non-zero status code
flake8_status=$?
if [ $flake8_status -ne 0 ]; then
    echo "Error, viola las reglas de flake8, revisar formato"
    exit $flake8_status
fi
