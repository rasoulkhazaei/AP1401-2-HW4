CXX = g++
CXXFLAGS = -std=c++23 -Wall -c
LXXFLAGS = -std=c++23
OBJECTS = main.o account.o banckingSystem.o checkingAccount.o creditAccount.o currency.o customer.o savingsAccount.o transaction.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: src/main.cpp include/account.h include/banckingSystem.h include/checkingAccount.h include/creditAccount.h include/currency.h include/customer.h include/savingsAccount.h include/transaction.h
	$(CXX) $(CXXFLAGS) src/main.cpp
transaction.o: src/transaction.cpp
	$(CXX) $(CXXFLAGS) src/transaction.cpp
currency.o: src/currency.cpp
	$(CXX) $(CXXFLAGS) src/currency.cpp
account.o: src/account.cpp
	$(CXX) $(CXXFLAGS) src/account.cpp
savingsAccount.o: src/savingsAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/savingsAccount.cpp
checkingAccount.o: src/checkingAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/checkingAccount.cpp
creditAccount.o: src/creditAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/creditAccount.cpp
banckingSystem.o: src/banckingSystem.cpp
	$(CXX) $(CXXFLAGS) src/banckingSystem.cpp
customer.o: src/customer.cpp
	$(CXX) $(CXXFLAGS) src/customer.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
