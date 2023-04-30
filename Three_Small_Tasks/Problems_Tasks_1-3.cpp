#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

/*class Customer
{
	std::string name;
	std::string address;
	std::string contactInformation;

public:
	Customer(std::string contactInformation = "", std::string name = "", std::string address = "")
	{
		this->contactInformation = contactInformation;
		this->name = name;
		this->address = address;
	}
};

class Account
{
public:
	enum TransactionType { Deposit, Withdraw };

	class Transaction
	{
	public:
		TransactionType type;
		double amount;

		Transaction(TransactionType type, double amount) : type{ type }, amount{ amount } {}
	};

	enum AccountType { Saving, Checking };

	AccountType type;
	Customer* customer;
	std::vector<Transaction> transactions;
	double balance;
	double interestRate;

	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	virtual void info() {};
	virtual ~Account() = default;
};

class SavingAccount : public Account
{
public:
	SavingAccount(Customer* customer)
	{
		type = Saving;
		this->customer = customer;
		balance = 0;
		interestRate = 0.5;
	}
	void deposit(double amount) override
	{
		if (amount >= 0)
		{
			balance += amount;
			transactions.push_back(Transaction{ Deposit, amount });
		}
		else
			std::cout << "Uncorrect amount\n";
	}
	void withdraw(double amount) override
	{
		if (amount >= 0)
		{
			balance -= amount;
			transactions.push_back(Transaction{ Withdraw, amount });
		}
		else
			std::cout << "Uncorrect amount\n";
	}
	void info() override
	{
		std::cout << "Saving type account\n";
		std::cout << "Balance = " << balance << '\n';
		std::cout << "Interest rate = " << interestRate << '\n';
	}
	void transactionInfo()
	{
		for (const Transaction& transaction : transactions)
			transaction.type == Deposit ? std::cout << "Deposit = " << transaction.amount << '\n' :
			std::cout << "Withdraw = " << transaction.amount << '\n';
	}
};

class CheckingAccount : public Account
{
public:
	CheckingAccount(Customer* customer)
	{
		type = Checking;
		this->customer = customer;
		balance = 0;
		interestRate = 0.5;
	}
	void deposit(double amount) override
	{
		if (amount >= 0)
		{
			balance += amount;
			transactions.push_back(Transaction{ Deposit, amount });
		}
		else
			std::cout << "Uncorrect amount\n";
	}
	void withdraw(double amount) override
	{
		if (amount >= 0)
		{
			balance -= amount;
			transactions.push_back(Transaction{ Withdraw, amount });
		}
		else
			std::cout << "Uncorrect amount\n";
	}
	void info() override
	{
		std::cout << "Saving type account\n";
		std::cout << "Balance = " << balance << '\n';
		std::cout << "Interest rate = " << interestRate << '\n';
	}
	void transactionInfo()
	{
		for (const Transaction& transaction : transactions)
			transaction.type == Deposit ? std::cout << "Deposit = " << transaction.amount << '\n' :
			std::cout << "Withdraw = " << transaction.amount << '\n';
	}
};

int main()
{
	Customer customer("John Doe", "123 Main St", "555-1234");
	SavingAccount savingAccount(&customer);
	savingAccount.deposit(1000);
	savingAccount.withdraw(500);
	savingAccount.info();
	savingAccount.transactionInfo();

	CheckingAccount checkingAccount(&customer);
	checkingAccount.deposit(2000);
	checkingAccount.withdraw(1000);
	checkingAccount.info();
	checkingAccount.transactionInfo();

	return 0;
}*/

/*class SalesPeople;
class Customer;
class SalesOperation;

enum CarType { ELECTRIC, HYBRID };

class Car
{
protected:
	std::string make;
	std::string model;
	double price;
	Customer* owner;

public:
	virtual CarType getType() const = 0;
	virtual void printDetails() = 0;
	virtual bool operator==(const Car*) = 0;
	virtual std::string getMake() const = 0;
	virtual std::string getModel() const = 0;
	virtual double getPrice() const = 0;
};

class ElectricCar: public Car
{
	CarType type;
	double batteryCap;

public:
	ElectricCar(std::string make, std::string model, double price, double batCap) : type{ELECTRIC}
	{
		this->make = make;
		this->model = model;
		this->price = price;
		batteryCap = batCap;
	}
	bool operator==(const Car* car) override
	{
		if (type == car->getType() && make == car->getMake() && model == car->getModel() 
		&& price == car->getPrice() && batteryCap == ((ElectricCar*)car)->getBatteryCap())
			return true;
		return false;
	}
	CarType getType() const override { std::cout << "Electric car\n"; return type; }
	std::string getMake() const override { return make; }
	std::string getModel() const override { return model; }
	double getPrice() const override { return price; }
	double getBatteryCap() const { return batteryCap; }
	void printDetails() override
	{
		std::cout << make << "\nModel: " << model << '\n' << "Price: " << price;
	}

};

class HybridCar: public Car
{
	CarType type;
	double batteryCap;
	double gasolineCap;

public:
	HybridCar(std::string make, std::string model, double price, double batCap, double gasCap) : type{ HYBRID }
	{
		this->make = make;
		this->model = model;
		this->price = price;
		batteryCap = batCap;
		gasolineCap = gasCap;
	}
	bool operator==(const Car* car) override
	{
		if (type == car->getType() && make == car->getMake() && model == car->getModel()
		&& price == car->getPrice() && batteryCap == ((HybridCar*)car)->getBatteryCap() 
		&& gasolineCap == ((HybridCar*)car)->getGasolineCap())
			return true;
		return false;
	}
	std::string getMake() const override { return make; }
	std::string getModel() const override { return model; }
	double getPrice() const override { return price; }
	double getBatteryCap() const { return batteryCap; }
	double getGasolineCap() const { return gasolineCap; }
	CarType getType() const override { std::cout << "Hybrid car\n"; return type; }
	void printDetails() override
	{
		std::cout << make << "\nModel: " << model << '\n' << "Price: " << price;
	}
};


class SalesOperation
{
	SalesPeople* saller;
	Customer* buyer;
	Car* car;

public:
	SalesOperation(SalesPeople* saller, Customer* buyer, Car* car) : saller{ saller }, buyer{ buyer }, car{ car } {}
};

class SalesPeople
{
	std::string name;
	double commissionRate;
	std::vector<Customer*> customers;
	std::list<Car*> carsForSale;
	std::vector<SalesOperation> saleHistory;

public:
	SalesPeople(std::string name, double commissionRate) : name{ name }, commissionRate{ commissionRate } {}
	void addCar(Car* car) { carsForSale.push_back(car); }
	void addCustomer(Customer* customer) { customers.push_back(customer); }
	Car* sellCar(Car* wishCar, Customer* customer)
	{
		for (Car* car : carsForSale)
		{
			if (wishCar == car)
			{
				saleHistory.push_back(SalesOperation(this, customer, car));
				auto iter = std::find(carsForSale.begin(), carsForSale.end(), car);
				carsForSale.erase(iter);
				return wishCar;
			}
		}
		return nullptr;
	}
};


class Customer
{
	std::string name;
	std::string contactInformation;
	std::vector<Car*> cars;
	
public:
	Customer(std::string name, std::string contact) : name{ name }, contactInformation(contact) {}
	std::string getName() { return name; }
	std::string getContact() { return contactInformation; }
	void buyCar(SalesPeople* saller, Car* wishCar)
	{
		Car* newCar = saller->sellCar(wishCar, this);
		if (newCar)
		{
			cars.push_back(newCar);
		}
	}
};


int main()
{
	Customer cust("Harut", "777");
	SalesPeople salPer("Arman", 1000);
	ElectricCar EQS("Mercedes", "E", 24000, 5000);
	salPer.addCar(&EQS);
	cust.buyCar(&salPer, &EQS);
}*/

class Dish;
class Order;
class Customer;

class Dish
{
protected:
	std::string name;
	double price;

public:
	virtual void display() const = 0;
	virtual double getPrice() const = 0;
};

class Appetizer: public Dish
{
public:
	Appetizer(std::string name, double price)
	{
		this->name = name;
		this->price = price;
	}
	void display() const override
	{
		std::cout << name << ": $" << price << '\n';
	}
	double getPrice() const override { return price; }
};

class Dessert : public Dish
{
public:
	Dessert(std::string name, double price)
	{
		this->name = name;
		this->price = price;
	}
	void display() const override
	{
		std::cout << name << ": $" << price << '\n';
	}
	double getPrice() const override { return price; }
};

class Menu
{
	std::vector<Dish*> dishes;

public:
	Menu(){}
	Menu(std::vector<Dish*> dishes)
	{
		this->dishes = dishes;
	}
	void insertDish(Dish* dish)
	{
		dishes.push_back(dish);
	}
	const std::vector<Dish*>& showMenu()
	{
		int i = 1;
		for (const Dish* const dish : dishes)
		{
			std::cout << i << ". ";
			dish->display();
			++i;
		}

		return dishes;
	}
};


class Order
{
	Customer* customer;
	Dish* dish;

public:
	Order(Customer* customer, Dish* dish) : customer{ customer }, dish{ dish } {}
	void seeDetails() const
	{
		std::cout << "The orders history of ";
		//customer->showName();
		dish->display();
	}
};

class Customer
{
	std::string name;
	std::string contactInformation;
	std::vector<Order> orderHistory;

public:
	Customer(std::string name, std::string contactInf): name{name}, contactInformation{contactInf} {}
	void getMenu(Menu* menu)
	{
		const std::vector<Dish*> dishes = menu->showMenu();
		std::cout << "Please say what you want\n";
		int i = 1;
		//std::cin >> i;
		if (i)
			orderHistory.push_back(Order(this, dishes[i]));
		else
			std::cout << "I don't wan't any of this dishes\n";
	}
	void seeOrderHistory()
	{
		for (const Order& order : orderHistory)
		{
			order.seeDetails();
		}
	}
	void showName() { std::cout << name << '\n'; }
};


int main()
{
	std::vector<Dish*> dishes;
	Appetizer appetizer("appetizer", 10);
	Dessert dessert("dessert", 15);
	dishes.push_back(&appetizer);
	dishes.push_back(&dessert);

	Menu menu(dishes);

	Customer customer("Harut", "777");
	customer.getMenu(&menu);

	customer.seeOrderHistory();

	return 0;
}