# Address Book Management System (ABMS)

## Overview

The Address Book Management System (ABMS) is a software application developed as part of an apprenticeship at Taiyuan University of Technology in May 2022. ABMS is designed to efficiently manage users' contact information, providing essential functionalities for creating, storing, retrieving, updating, and deleting contact details.

## Features

### Basic Functionality:

1. **Create and Insert:** Users can create new information cards and insert them into the address book.
2. **Show Details:** Detailed information of all stored cards can be displayed.
3. **Search:** Users can search for information items using specific criteria, such as name.
4. **Update:** Functionality is provided to update information based on user input.
5. **Delete:** Users can delete specific cards by name.

### Advanced Functionality:

1. **File Storage:** Data is stored persistently in a binary file named "abms.bin."
2. **Keyword Search:** Users can search for information items using different keywords, such as name, gender, etc.
3. **Graphical User Interface (GUI):** ABMS offers a user-friendly GUI for easy interaction.
4. **Data Input Verification:** Input verification ensures data integrity, preventing invalid entries.
5. **Additional Features:** ABMS is extensible, allowing for the addition of extra features to enhance functionality.

### Database Management System Similarity

The functionalities of ABMS, particularly its storage mechanism using a binary file named "abms.bin," share similarities with Database Management Systems (DBMS). By employing persistent storage and providing functionalities for data manipulation, ABMS demonstrates a simplified version of database management, suitable for smaller-scale applications such as managing personal contacts. This approach underscores the practical application of fundamental database concepts within a specific use case, showcasing skills in software development and database design.

## Implementation Details

ABMS is implemented in C++ programming language using the Embarcadero RAD Studio IDE. It employs object-oriented programming principles and utilizes the following components:

- **Person Class:** A class named "Person" is designed to encapsulate user information, including name, phone number, email address, age, and gender.
- **Data Structures:** Vectors are used for storing Person objects in memory, providing efficient data management.
- **File Storage:** User information is stored in binary format in the "abms.bin" file for permanent storage.
- **User Interface:** ABMS offers both Console and GUI applications, providing flexibility in user interaction.
- **Validation:** Input validation is implemented within the Person class to ensure data consistency and integrity.

## Usage

### Console Application:

To run the Console Application:

1. Compile the source files using a C++ compiler.
2. Execute the generated executable file.
3. Follow the on-screen prompts to interact with the application.

--- or ---

You can directly run the Win64/Release/AddressBookManagementSystem.Console.exe

### GUI Application:

To run the GUI Application:

1. Launch the application using the provided executable file inside the release folder in Win32 or Win64.
2. Use the graphical interface to perform various operations on the address book.

## Conclusion

The Address Book Management System (ABMS) provides a robust solution for managing contact information, demonstrating proficiency in software development and database management principles. For further inquiries or support, please contact `agajan.st@gmail.com`.
