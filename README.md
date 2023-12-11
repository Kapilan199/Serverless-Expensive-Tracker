# Company Expense Tracker
 
 Authors: [Kapilan Ramasamy](https://github.com/Kapilan199), [Mike Chavez](https://github.com/mchav138), [David Frias-Sanchez](https://github.com/SirBossDavid), [Miguel Gallegos](https://github.com/mgall063)

## Project Description
The Company Expense Tracker is a C++ application designed for financial management and expense tracking processes within a company or organization. It serves as a centralized platform that enables employees to log their expenses and provides administrators with the ability to manage, monitor, and control company spending effectively. This project addresses a critical need for businesses, especially in an age where financial efficiency is paramount.

The project offers an opportunity to integrate various software tools to address the complexities of expense management, which we find both fascinating and intellectually rewarding. The technologies and languages we will be using encompass databases, user interfaces, backend, and security through C++, MySQL, HTML/CSS, and JavaScript.

Input for the system will consist of employee-submitted expense reports, including details such as date, amount, category, and description/notes. The output will comprise comprehensible expense reports, displaying detailed records of expenses.

Some key features of the project will include expense entry, expense categories, data storage, expense reports, budget management, search and filtering, as well as data analytics and visualization.

## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/diagram%20(2).jpg?raw=true)


> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-08%20154109.png?raw=true)

entering user log-in info in order to get access to submitting company expense IDs and links to screen for making new account
![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-08%20154213.png?raw=true)

creating a new account if you have not obtained one yet
![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-08%20154226.png?raw=true)

reading expense entry description, as well as viewing the date, category, and amount of the expense entry. Admins will be able to view the submitter's ID.

> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
![image](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/assets/146979886/a31d2b9f-525a-406e-bc80-22baaf22a42e)


For each company using the expense tracker there will be an object/instantiation of the Company class. This class is basically a large container to link the expense logs and employees to. It will also contain some company information which may be used in graphs or expense entries depending on implementation.

for every company there is a positive integer of employees and admins, as well as atleast one expense entry vector.

The employee and admin classes are sub-types of the company member class. Employees can submit expense reports but are not allowed to delete them or modify after submission (this is reserved for admins who should be allowed higher permissions and are to be trusted with such permissions).

each company member will be associated with an account, mostly to link expense entries of employees with an account so you (an Administrator) can see the ID of the person who submitted the expense entry.

Expense entries are comprised of an ID, category, amount, date, and a description of the expense entry (they also contain submitter ID as previously discussed). The idea is that both expense plans and entries will function the same and will both be some instantiation of this class (thus planning will simply mean the entry belongs to the planning category rather than having a different class for this).

UML Update 2:
company class was deemed unnecessary but could be implemented in the future

SRP: We decided on the creation of the registry class as the Employee class was previously responsible for holding accounts and felt that violated this principle.

OCP: The expense entry classes display function could be overided to display in different forms. In the future we could add different ways to display the information without needing to modify what is there.

LSP: The employee and admin classes already fulfil what is asked of the LSP as you can substitute either for the company member type and its still functional. Although that wouldn't be necessary as the company member class itself is never used (only implemented to reduce duplicate code)

ISP: This is the reason for the removal of the company class as it doesn't make sense to include it until there is a reason to have more than one company accessed from a device. All other data types and objects are going to be used.

DIP: Our classes don't depend on low level modules, ExpenseEntry's ability to display depends on the methods in the inherited classes but I believe that to be more of a form of abstraction. (Not reflective of it's current state but if we were to extend the display function this is likely how we would do it)

### Screen Layouts
![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-22%20123345.png?raw=true)

entering user log-in info in order to get access to submitting company expense IDs and links to screen for making new account
![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-22%20123350.png?raw=true)

creating a new account if you have not obtained one yet
![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-22%20123354.png?raw=true)

employee's screen linking to screens shown later, treated as main screen

![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-22%20123358.png?raw=true)

admin's screen also treated as a main screen linking to later screens, some of which are admin exclusive.

![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-22%20123402.png?raw=true)
screen for viewing employees (admins only)

![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-22%20123406.png?raw=true)
screen for viewing budget, admins can see id of the submitter

![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-22%20123411.png?raw=true)
screen for modifying budget/expenses (admins only)

![alt text](https://github.com/cs100/final-project-dfria006-mchav138-mgall063-krama018/blob/master/Screenshot%202023-11-22%20123415.png?raw=true)
screen for submitting an expense

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
> ![alt text](https://i.ibb.co/tbSWc9C/Screenshot-2023-12-06-at-4-36-33-PM.png)
>  ![alt text](https://i.ibb.co/TrGFVTf/Screenshot-2023-12-06-at-4-37-26-PM.png)
>
> ## Class Diagram
![alt text](https://i.ibb.co/jGRymcv/class-diagram.jpg)

 ## Installation/Usage
   To start, we must use a node.js file to host an http local server using html and javascript. The user first logins as an employee or admin. 
    
   If the the user logins as an employee then they taken to a data entry page where they enter their information. After pressing enter the data is then inserted into a serverless sqlite database.

   If the user logins as an admin then they are taken to a data entry page where they can also enter their information. After pressing enter the data is then inserted into the serverless sqlite database. They also have the option to view the data by clicking on the button "display" which will give them the oppurtunity to see all the data recorded in the sqlite database.

 ## Usage commands
   To start the project in the html directory we first run: 
   
    node script.js 
   To test valgrind in the project directory we run:
   
    cmake . && make && valgrind --leak-check=full --track-origins=yes ./display 
   To run unit tests in the project directory we run: 
   
      cmake . && make && ./test 


 ## Testing

 The project was tested using the google unit tests on the admin, employee, and expenseEntry classes. Also standard input/output check was used to make sure that the input in the text field matches the output in the sqlite database.

 
