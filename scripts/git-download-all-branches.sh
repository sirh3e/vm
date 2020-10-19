#!/bin/bash

for branch in $(git branch --all | grep '^\s*remotes' | grep -E --invert-match '(:?HEAD|master)$'); do
        git branch --track "${branch##*/}" "$branch"
done
