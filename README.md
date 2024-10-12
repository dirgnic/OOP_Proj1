### README for the OOP Project: "Perfume Store Inventory Management System"

#### Project Overview
This project is a C++ application as homework for my OOP class. It is designed to simulate an inventory management system for a perfume store. The program allows users to manage perfumes, employees, sales, and store inventory through various functionalities such as creating, reading, updating, and deleting records. It also includes additional features like estimating employee salaries, tracking inventory stock, and determining the sales status of perfumes.

#### Classes Overview
The project revolves around four core classes: `Parfum`, `Angajat`, `Vanzare`, and `InventarMagazin`, each representing a different entity in the store.

1. **Parfum (Perfume)**
   - Represents a perfume with attributes such as `idParfum`, `numeParfum` (name), `brand`, `rating`, `tipAroma` (scent type), availability (`inStoc`), and price.
   - The class supports multiple constructors, including those for creating a default object, one with full parameters, and others for specific subsets of parameters.
   - It implements various methods for updating the object’s state (`set` and `get` methods), operator overloads, and a unique function `perioadaDeVarf()` that predicts when the perfume will sell best based on its rating.

2. **Angajat (Employee)**
   - Represents a store employee with attributes such as `idAngajat`, `nume` (name), `post` (position), employment status (`inActivitate`), and salary.
   - The class includes functionality to estimate future salaries based on monthly raises (`salariuEstimat()`), as well as operator overloading for assignment and comparison.

3. **Vanzare (Sale)**
   - Represents a sale transaction with attributes like `idVanzare`, `idAngajat` (employee ID handling the sale), `numeClient` (customer name), `sumaTotala` (total amount), and a list of perfumes purchased.
   - This class allows for checking if specific perfumes were part of a sale using the `parfumCumparat()` method. It also supports overloading operators for equality, comparison, and manipulating purchase details.

4. **InventarMagazin (Store Inventory)**
   - Represents the store's perfume inventory, containing attributes like `numarTipParfumuri` (number of different perfumes), `listaIdParfumuri` (IDs of perfumes), `bucatiInStoc` (quantity in stock), and the total profit.
   - Includes functionality to check how many units of a specific perfume are in stock (`bucatiInventar()`).

#### Key Features
- **CRUD Operations**: Users can create, read, update, and delete instances of perfumes, employees, sales, and inventory.
- **Salary Estimation**: Calculates potential salary growth for employees over a number of months.
- **Inventory Management**: Tracks the number of perfume units in stock and can update the store's inventory dynamically.
- **Sales Tracking**: Checks if specific perfumes are part of a sale transaction.
  
#### Operator Overloading
Each class supports several operator overloads for comparison, assignment, incrementing, indexing, and arithmetic operations. For example:
- `Parfum operator+(char *s)` appends additional text to the perfume name.
- `Vanzare operator*(int sum)` multiplies the total sale value.

#### User Interaction
The program is interactive, with a menu-driven interface where users can:
1. Create new records (perfume, employee, sale, inventory).
2. Read existing records.
3. Update existing records.
4. Delete records.
5. Call specific functions to display perfume sales performance, estimate employee salaries, or check inventory status.

#### Usage
To run the program, compile and execute it. The program will display an interactive menu that guides the user through different options, such as creating or managing perfumes, employees, and sales.

#### Future Improvements
- **File Persistence**: Add functionality to save data to files so that records persist between program executions.
- **Error Handling**: Enhance error handling for user input, such as ensuring valid indices when updating or deleting records.
- **GUI**: Develop a graphical user interface (GUI) for a more intuitive user experience.

This project demonstrates object-oriented programming (OOP) concepts such as encapsulation, inheritance, operator overloading, and dynamic memory management using pointers.
