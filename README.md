This package includes publisher/subscriber node and server/client node written in Python and C++

Writing a node in C++
    1. Write the node in the src directory within the package.
    2. Add add_executable() and target_link_libraries() to CMakeLists.txt.
    3. Run catkin_make.
    4. Execute the node.
    
Writing a node in Python
    1. Write the node in the scripts directory within the package.
    2. Grant execution permission using chmod +x.
    3. Run catkin_make.
    4. Source the setup file: source devel/setup.bash.
    5. Execute the node.
