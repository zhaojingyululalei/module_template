# module_template
在src中写.c
在include 中写.h
输出到和makefile同级目录

~~~shell
#!/bin/bash

# create_driver_env - A script to clone a driver template and rename it

# Check if running with arguments
if [ $# -eq 0 ]; then
    echo "Usage: $0 [project_name] [git_repo_url]"
    echo "Example: $0 chrdev git@github.com:zhaojingyululalei/module_template.git"
    exit 1
fi

PROJECT_NAME=$1
GIT_REPO=${2:-"git@github.com:zhaojingyululalei/module_template.git"}

# Clone the repository
echo "Cloning template repository..."
git clone "$GIT_REPO" || {
    echo "Error: Failed to clone repository"
    exit 1
}

# Check if clone was successful
if [ ! -d "module_template" ]; then
    echo "Error: Expected 'module_template' directory not found after clone"
    exit 1
fi

# Rename the directory
echo "Renaming module_template to $PROJECT_NAME..."
mv "module_template" "$PROJECT_NAME" || {
    echo "Error: Failed to rename directory"
    exit 1
}

# Navigate into the project directory
cd "$PROJECT_NAME" || {
    echo "Error: Failed to enter project directory"
    exit 1
}

echo "Project $PROJECT_NAME created successfully from template."
echo "You are now in the project directory: $(pwd)"

进行一下操作，以后通过create_driver_env xxx(项目名称)创建环境
chmod +x create_driver_env
sudo mv create_driver_env /usr/local/bin/
create_driver_env chrdev