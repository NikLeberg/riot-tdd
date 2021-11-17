# Loop over all folders and execute specified target
dirs=($(find . -maxdepth 1 -mindepth 1 -type d))
for dir in "${dirs[@]}"; do
    cd "$dir"
    make $1
done
