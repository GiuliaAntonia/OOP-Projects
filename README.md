# OOP-Projects

Projects implemented for the OOP lab

## Project 1 - Library management :books:
Implemented a mini-application with an interactive menu that manages a library. It includes five clases: 
* Library: which include information such as: location, year of establishment, number of employees, and a list of employees 
* Employee: which includes information about employees such as: name, age, salary, expenses, years of work
* Book: which contains information regarding books: totle, author, cantity, availability
* Members: information with regard to people who borrow books: name, status (adult, student or unknown), number of borrowed books, number of unreturned books, list of books to borrow
* Borrowing: information about daily borrowings at a library: data, number of members who borrow books at the given date

Interactive menu features:
* add books, employees and members to the library
* list of employees in ascending order based on salary
* list of members sorted in ascending order based on the number of borrowed books
* delete/edit books
* print devoted members (a devoted member is someone who borrowed more than 100 books and returned them all)

## Project 3 - Online shop management 	:computer:
Is a continuation of the second project containing more menu features, singleton class, template classes and functions, vectors, lists and maps
Implemented a mini-application with interactive menu that manages an online shop that sales books and perfumes. It includes five clases: 
* Product details: genral details included in both books and perfumes (name, price, discount, cantity)
* Books: beside product details it includes author, discount code
* Perfumes: beside product details it includes the number of ml
* Costumer: detail about the person buying products: costumer id, postal code
* Order: order id

Interactive menu features:
* add costumers, books, perfumes
* list the prices before the discount of the books/perfumes
* list books sorted in ascending order on prices
* list perfumes sorted in descending order based on discount
* list all available products
* list costumers in alphabetical order
* place an order
* calculate the cost of transportation (if the total of your order is more than 200 ron then your trnasportation is free, otherwise you pay 15 ron)
* calculate discount (the sum of money you saved up by buying books on sale)

