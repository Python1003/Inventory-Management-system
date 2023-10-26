# Inventory-Management-system
The Inventory Management System is a C++ program designed for retail stores to manage their product inventory efficiently. This system allows store owners to add, remove, update, and view products in their inventory. It also provides the ability to save and load the inventory from a file for persistent data storage.


**Code Description: Inventory Management System**

1. **Classes**: The program defines three classes, which are as follows:

   - `InventoryItem`: This is a base class that represents common attributes shared by all items in the inventory. It includes an ID and a name for each item.

   - `Product`: A derived class from `InventoryItem`, this class represents individual products. It extends the base class by adding specific attributes for products such as category, price, and quantity.

   - `Inventory`: This class manages a vector of `Product` objects, providing functionality to add, remove, find, update, and print product details.

2. **Function Overloading**: The `Inventory` class features function overloading, allowing you to update products in multiple ways. You can update the name, all product details (name, category, price, quantity), or only the quantity of a product.

3. **User Interaction**: The program interacts with users through a simple console-based menu. Users can choose options to add a product, remove a product, find a product by ID, update a product's information, or view all products. There is also an option to quit the program.

4. **Inheritance**: The code makes use of inheritance to create a clear hierarchy between `InventoryItem` and `Product`, allowing for code reuse and promoting a more organized structure.

5. **Output Messages**: The program provides informative messages to the user to confirm the success or failure of various operations, helping to ensure the user understands the system's responses.

6. **Loop-Based Menu**: The program features a loop-based menu, allowing users to perform multiple operations without restarting the program.

7. **Graceful Exit**: The program offers a "Quit" option for users to exit the system gracefully.


