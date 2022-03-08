# Project 1: Employee Database
## Objective
### Using Bash, develop a mini-database system to manage employee information. Your database should allow users to insert, delete, modify and retrieve employee records. All the data in the database is stored in an external file called “employee.db”.
## Requirements
### The program supports the following operations:
#### For INSERT operation, users need to provide all the information for an employee. Some information should be validated before they are entered into database. SSN should be exactly nine digits with “-“ in between. First name and last name should contain less than 10 characters each. Birthday must be in the format of MM-DD-YYYY. Salary must be positive. Please note that every employee should have their unique SSN. If a new employee to be added to the database has the same SSN as an existing one, the new employee information will not be entered into the database and a warning message should be given.
#### For MODIFY operation, users need to provide the SSN first. Then the information for that employee will be retrieved and displayed. The users can modify the all the fields of an employee except the SSN. New information to be inserted must be validated (like INSERT) before the employee record is updated. Your program should prompt the users for confirmation for the final updated.
#### For DELETE operation, users need to provide the SSN. Before the employee record is deleted, your program should prompt the users for confirmation.
#### For RETRIEVE operation, the database should allow users to retrieve information by any one of the following criteria: 1) SSN 2) last name 3) first name 4) salary and display the information about the employees who meet the search criteria. The information displayed should look similar to below (nicely line-up and formatted) and sorted by the search criteria
#### DisplayMenu function-> display a menu for users to make a selection of an operation.
#### PrintDatabase->display data in proper format on screen
#### Use of color in the console display to make it pleasant for users
## Overall Performance
