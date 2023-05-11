CXX = g++
CXXFLAGS = -std=c++23 -Wall  -c
LXXFLAGS = -std=c++23
OBJECTS = main.o account.o savingsAccount.o checkingAccount.o creditAccount.o transaction.o customer.o currency.o bankingSystem.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: src/main.cpp include/.
	$(CXX) $(CXXFLAGS) src/main.cpp
account.o: src/account.cpp
	$(CXX) $(CXXFLAGS) src/account.cpp
savingsAccount.o: src/savingsAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/savingsAccount.cpp
checkingAccount.o: src/checkingAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/checkingAccount.cpp
creditAccount.o: src/creditAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/creditAccount.cpp
transaction.o: src/transaction.cpp
	$(CXX) $(CXXFLAGS) src/transaction.cpp	
customer.o: src/customer.cpp
	$(CXX) $(CXXFLAGS) src/customer.cpp
bankingSystem.o: src/bankingSystem.cpp
	$(CXX) $(CXXFLAGS) src/bankingSystem.cpp
currency.o: src/currency.cpp
	$(CXX) $(CXXFLAGS) src/currency.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
