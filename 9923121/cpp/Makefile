CXX = g++
CXXFLAGS = -std=c++23 -Wall -c
LXXFLAGS = -std=c++23
OBJECTS = main.o src/account.o src/backingSystem.o src/creditAccount.o src/currency.o src/customer.o src/savingsAccount.o src/transaction.o src/CheckingAccount.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: src/main.cpp include/account.h include/backingSystem.h include/creditAccount.h include/currency.h include/customer.h include/savingsAccount.h include/transaction.h
	$(CXX) $(CXXFLAGS) src/main.cpp

account.o: src/account.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/account.cpp

backingSystem.o: src/backingSystem.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/backingSystem.cpp

creditAccount.o: src/creditAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/creditAccount.cpp

currency.o: src/currency.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/currency.cpp

customer.o: src/customer.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/customer.cpp

savingsAccount.o: src/savingsAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/savingsAccount.cpp

transaction.o: src/transaction.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/transaction.cpp

CheckingAccount.o: src/CheckingAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/CheckingAccount.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
