Projects implemented for the OOP lab

## Project 1 - Library management 📚
Implemented a mini-application with an interactive menu that manages a library. It includes five classes:

* Library: which includes information such as location, year of establishment, number of employees, and a list of employees
* Employee: which includes information about employees such as name, age, salary, expenses, years of work
* Book: which contains information regarding books: title, author, quantity, availability
* Members: information with regard to people who borrow books: name, status (adult, student, or unknown), number of borrowed books, number of unreturned books, list of books to borrow
* Borrowing: information about daily borrowings at a library: data, number of members who borrow books on the given date

Interactive menu features:
* add books, employees, and members to the library
* list of employees in ascending order based on salary
* list of members sorted in ascending order based on the number of borrowed books
* delete/edit books
* print devoted members (a devoted member is someone who borrowed more than 100 books and returned them all)


## Project 3 - Online shop management 💻
Is a continuation of the second project containing more menu features, singleton classes, template classes and functions, vectors, lists and maps Implemented a mini-application with an interactive menu that manages an online shop that sells books and perfumes. It includes five classes:

* Product details: general details included in both books and perfumes (name, price, discount, quantity)
* Books: beside product details, it includes author, discount code
* Perfumes: beside product details, it includes the number of ml
* Customer: detail about the person buying products: customer id, postal code
* Order: order id

Interactive menu features:
* add customers, books, perfumes
* list the prices before the discount on the books/perfumes
* list books sorted in ascending order on prices
* list perfumes sorted in descending order based on the discount
* list all available products
* list customers in alphabetical order
* place an order
* calculate the cost of transportation (if the total of your order is more than 200 ron then your transportation is free, otherwise you pay 15 ron)
* calculate discount (the sum of money you saved up by buying books on sale)
