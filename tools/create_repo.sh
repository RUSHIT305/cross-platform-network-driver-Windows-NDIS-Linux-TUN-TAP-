#!/usr/bin/env bash
# Helper to initialize git repo and push to GitHub.
# Usage: ./create_repo.sh <github-username> <repo-name>
if [ $# -ne 2 ]; then
  echo "Usage: $0 <github-username> <repo-name>"
  exit 1
fi
USER=$1
REPO=$2
git init
git add .
git commit -m "Initial commit - cross-netdriver skeleton"
gh repo create "$USER/$REPO" --public --source=. --remote=origin --push
