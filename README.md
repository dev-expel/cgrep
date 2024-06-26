# CGREP

#### Usage
- ./cgrep term -f file_path
- ./cgrep -f file_path term

### data struct
- char* src_file_path
- char* search_term

### main
- collecting the src_file_path and search_term from the command line args
- validate the command line arguments
- get the text from within the src file
- collect the lines of text that contain the search term (storing that into a valid text char*)
- print out the valid text to the user