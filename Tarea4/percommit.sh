#!/bin/bash

git diff --staged --name-only | grep '\.py$' | xargs flake8

if [ $? -ne 0 ]; then
    echo "Error en flake8, revisar formato..."
    exit 1
fi
