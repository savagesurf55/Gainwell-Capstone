#!/bin/bash

SRC_DIR="/home/student/Capstone/"
DST_DIR="/home/student/Capstone/Backup/"

# Check if the destination directory exists, if not, create it
if [ ! -d "$DST_DIR" ]; then
    mkdir -p "$DST_DIR"
fi

# Check if the source directory exists
if [ ! -d "$SRC_DIR" ]; then
    echo "ERROR: Source Directory does not exist!"
    exit 1
fi

# Backup MySQL database using .my.cnf for credentials
mysqldump --defaults-extra-file=/home/student/Capstone/.my.cnf hospital > "$DST_DIR/hospital_backup.sql"

# Copy all files and directories recursively into the backup directory
# Use rsync instead of cp to exclude the destination directory
rsync -av --exclude="$DST_DIR" "$SRC_DIR" "$DST_DIR"

echo "Backup completed."


#automation sudo crontab -e code
#0 18 * * * /home/student/Capstone/FullBackup.sh
#0 18 * * * /home/student/Capstone/FullBackup.sh >> /home/student/Capstone/full_backup.log 2>&1
