#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a directory
void create_directory(char *path) {
    #ifdef _WIN32
    // For Windows
    _mkdir(path);
    #else
    // For Linux and macOS
    mkdir(path, 0777);
    #endif
}

// Function to create a file
void create_file(char *path, char *content) {
    FILE *file = fopen(path, "w");
    if (file != NULL) {
        fprintf(file, "%s", content);
        fclose(file);
    } else {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
}

// Function to generate the boilerplate structure
void generate_boilerplate(char *project_name) {
    char src_path[100];
    char include_path[100];
    char obj_path[100];
    char bin_path[100];
    char tests_path[100];
    char docs_path[100];
    char makefile_path[100];
    char readme_path[100];

    // Create directory paths
    sprintf(src_path, "%s/src", project_name);
    sprintf(include_path, "%s/include", project_name);
    sprintf(obj_path, "%s/obj", project_name);
    sprintf(bin_path, "%s/bin", project_name);
    sprintf(tests_path, "%s/tests", project_name);
    sprintf(docs_path, "%s/docs", project_name);

    // Create directories
    create_directory(project_name);
    create_directory(src_path);
    create_directory(include_path);
    create_directory(obj_path);
    create_directory(bin_path);
    create_directory(tests_path);
    create_directory(docs_path);

    // Create files
    sprintf(makefile_path, "%s/Makefile", project_name);
    sprintf(readme_path, "%s/README.md", project_name);

    char makefile_content[] =
        "CC = gcc\n"
        "CFLAGS = -Wall -g\n\n"
        "SRC_DIR = src\n"
        "INCLUDE_DIR = include\n"
        "OBJ_DIR = obj\n"
        "BIN_DIR = bin\n\n"
        "SRC_FILES = $(wildcard $(SRC_DIR)/*.c)\n"
        "OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))\n\n"
        "TARGET = $(BIN_DIR)/executable\n\n"
        "$(TARGET): $(OBJ_FILES)\n"
        "\t$(CC) $(CFLAGS) -o $@ $^\n\n"
        "$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c\n"
        "\t$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<\n\n"
        "clean:\n"
        "\trm -rf $(OBJ_DIR)/*\n"
        "\trm -rf $(BIN_DIR)/*\n\n"
        "docs:\n"
        "\t# Add commands to generate documentation\n";

    char readme_content[] =
        "# Project Title\n\n"
        "## Overview\n\n"
        "Brief project overview goes here.\n\n"
        "## Build and Run\n\n"
        "Instructions on how to build and run the project.\n\n"
        "## Documentation\n\n"
        "Any additional documentation or notes.\n";

    create_file(makefile_path, makefile_content);
    create_file(readme_path, readme_content);

    printf("Boilerplate for project '%s' created successfully!\n", project_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <project_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    generate_boilerplate(argv[1]);

    return 0;
}
