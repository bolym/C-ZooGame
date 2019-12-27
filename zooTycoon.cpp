#include "zooTycoon.hpp"

/************ANIMAL CLASS*****************/

Animal::Animal(){
  //empty
}

int Animal::getAge(){
  return age;
}

int Animal::getPrice(){
  return price;
}

int Animal::getNumBabies(){
  return numBabies;
}

int Animal::getFoodCost(){
  return foodCost;
}

int Animal::getRevenue(){
  return revenue;
}

void Animal::incrementAge(){
  age++;
}


/************SLOTH CLASS*****************/

Sloth::Sloth(){
  //empty
}

Sloth::Sloth(int days){
  age = days;
  price = 2000;
  numBabies = 3;
  foodCost = 1;
  revenue = 100;

}

/************SEAOTTER CLASS*****************/

SeaOtter::SeaOtter(){
  //empty
}

SeaOtter::SeaOtter(int days){
  age = days;
  price = 5000;
  numBabies = 2;
  foodCost = 2;
  revenue = 250;

}

/************MONKEY CLASS*****************/

Monkey::Monkey(){
  //empty
}

Monkey::Monkey(int days){
  age = days;
  price = 15000;
  numBabies = 1;
  foodCost = 4;
  revenue = 1500;

}


/************ZOO CLASS*****************/

Zoo::Zoo(){
  bankAccount = 100000;
  numAnimals = 0;
  numMonkey = 0;
  monkeys = new Monkey[0];
  numSeaOtter = 0;
  seaOtters = new SeaOtter[0];
  numSloth = 0;
  sloths = new Sloth[0];
  baseFoodCost = 50;
  bankrupt = false;
}

Zoo::~Zoo(){
  delete[] monkeys;
  delete[] seaOtters;
  delete[] sloths;
}

void Zoo::displayGame(){
  /* show bankAccount */
  cout << "Bank Account Balance: " << bankAccount << endl;
  cout << "Total Number of Animals: " << numAnimals << endl;

  /* show monkeys */
  cout << "Monkeys: " << endl;
  cout << "---------------------" << endl;
  cout << "Number of Monkeys: " << numMonkey << endl;
  /* calculate adults and babies */
  int numAdult = 0;
  int numBaby = 0;
  for(int i = 0; i < numMonkey; i++){
    if(monkeys[i].getAge() < 30){
      numBaby++;
    }
    if(monkeys[i].getAge() > 1094){
      numAdult++;
    }
  }
  cout << "Adult: " << numAdult << endl;
  cout << "Baby: " << numBaby << endl << endl;

  /* show seaOtters */
  cout << "Sea Otters: " << endl;
  cout << "---------------------" << endl;
  cout << "Number of Sea Otters: " << numSeaOtter << endl;
  /* calculate adults and babies */
  numAdult = 0;
  numBaby = 0;
  for(int i = 0; i < numSeaOtter; i++){
    if(seaOtters[i].getAge() < 30){
      numBaby++;
    }
    if(seaOtters[i].getAge() > 1094){
      numAdult++;
    }
  }
  cout << "Adult: " << numAdult << endl;
  cout << "Baby: " << numBaby << endl << endl;

  /* show sloths */
  cout << "Sloths: " << endl;
  cout << "---------------------" << endl;
  cout << "Number of Sloths: " << numSloth << endl;
  /* calculate adults and babies */
  numAdult = 0;
  numBaby = 0;
  for(int i = 0; i < numSloth; i++){
    if(sloths[i].getAge() < 30){
      numBaby++;
    }
    if(sloths[i].getAge() > 1094){
      numAdult++;
    }
  }
  cout << "Adult: " << numAdult << endl;
  cout << "Baby: " << numBaby << endl << endl;
}

void Zoo::addMonkey(int age){
  Monkey monk(age);
  Monkey* temp = new Monkey[numMonkey+1];

  /* copy over */
  for(int i = 0; i < numMonkey; i++){
    temp[i] = monkeys[i];
  }
  /* addOne */
  temp[numMonkey] = monk;
  numMonkey++;
  numAnimals++;

  delete[] monkeys; /* delete old */
  monkeys = temp; /* reassign */

  if(age == 1095){ /* if this is a purchase vs birth */
    bankAccount = bankAccount - monk.getPrice(); /* subtract price */
  }
}

void Zoo::addSeaOtter(int age){
  SeaOtter otter(age);
  SeaOtter* temp = new SeaOtter[numSeaOtter+1];
  /* copy over */
  for(int i = 0; i < numSeaOtter; i++){
    temp[i] = seaOtters[i];
  }

  /* addOne */
  temp[numSeaOtter] = otter;
  numSeaOtter++;
  numAnimals++;

  delete[] seaOtters;   /* delete old */
  seaOtters = temp;   /* reassign */

  if(age == 1095){ /* if this is a purchase vs birth */
    bankAccount = bankAccount - otter.getPrice();  /* subtract price */
  }
}

void Zoo::addSloth(int age){
  Sloth slo(age);
  Sloth* temp = new Sloth[numSloth+1];

  /* copy over */
  for(int i = 0; i < numSloth; i++){
    temp[i] = sloths[i];
  }

  /* addOne */
  temp[numSloth] = slo;
  numSloth++;
  numAnimals++;

  delete[] sloths;   /* delete old */
  sloths = temp;   /* reassign */

  if(age == 1095){   /* if this is a purchase vs birth */
    bankAccount = bankAccount - slo.getPrice(); /* subtract price */
  }
}

void Zoo::buyAnimal(){
  cout << "Animal Prices: Monkey $15,000| SeaOtter $5,000| Sloth $2,000" << endl;
  int numBuy = -1;
  numBuy = checkInput("Enter the number of adult animals you want to buy: ", "012");
  if(numBuy > 0){
    int species = 0;
    species = checkInput("Enter 1 for Monkey, 2 for Sea Otter, or 3 for Sloth: ", "123");
    for(int i = 0; i < numBuy; i++){
      if(species == 1){ /* monkey */
        addMonkey(1095);
      }
      if(species == 2){ /* seaOtter */
        addSeaOtter(1095);
      }
      if(species == 3){ /* sloth */
        addSloth(1095);
      }
    }
    cout << endl << "You bought " << numBuy << " adult animal(s)!" << endl;
    cout << "Your new Bank Account Balance is: " << bankAccount << endl << endl;
    if(bankAccount < 0){ /* check for bankrupcy */
      bankrupt = true;
    }
  } else {
    cout << endl << "You chose to buy no animals today." << endl << endl;
  }
}

void Zoo::feedAnimals(){
  int sumFoodCost = 0;
  /* feed monkeys */
  for(int i = 0; i < numMonkey; i++){
    sumFoodCost += (monkeys[i].getFoodCost() * baseFoodCost);
  }
  /* feed seaOtters */
  for(int i = 0; i < numSeaOtter; i++){
    sumFoodCost += (seaOtters[i].getFoodCost() * baseFoodCost);
  }
  /* feed sloths */
  for(int i = 0; i < numSloth; i++){
    sumFoodCost += (sloths[i].getFoodCost() * baseFoodCost);
  }

  bankAccount = bankAccount - sumFoodCost;
  if(bankAccount < 0){ /* check for bankrupcy */
    bankrupt = true;
  }

  int randPercent = rand() % 51 + 75; /* generate new base food cost */
  baseFoodCost = (baseFoodCost * randPercent) / 100;

  cout << "You fed all the animals!" << endl;
  cout << "Your new Base Food Cost is: " << baseFoodCost << endl;
  cout << "Your new Bank Account Balance is: " << bankAccount << endl << endl;

}

Animal* Zoo::getRandAnimal(){

  Animal* aPtr;
  bool found = false;
  while(!found){
    int type = rand() % 3 + 1; /* pick random species */
    switch(type){
      case 1: {
        if(numMonkey > 0){
          int ind = rand() % numMonkey; /* then pick random one */
          aPtr = &monkeys[ind];
          found = true;
        }
        break;
      }
      case 2: {
        if(numSeaOtter > 0){
          int ind = rand() % numSeaOtter;
          aPtr = &seaOtters[ind];
          found = true;
        }
        break;
      }
      case 3: {
        if(numSloth > 0){
          int ind = rand() % numSloth;
          aPtr = &sloths[ind];
          found = true;
        }
        break;
      }
    }
  }
  return aPtr;
}

void Zoo::makeSick(){
  cout << "Oh No! One of your animals got sick!" << endl;
  Animal* randAnimal = getRandAnimal();
  int payment = 0;
  if(randAnimal->getAge() < 30){ /* sick baby */
    cout << "The sick animal is a baby." << endl;
    payment = randAnimal->getPrice();
  } else {
    payment = randAnimal->getPrice() / 2;
  }

  /* live or die */
  if(bankAccount >= payment){
    cout << "You can afford to pay for the sick animal!" << endl;
    bankAccount = bankAccount - payment;
    cout << "Your new Bank Account Balance is: " << bankAccount << endl << endl;
  } else {
    int type = randAnimal->getNumBabies();
    switch(type){
      case 1: /* monkey */
        cout << "The sick animal is a Monkey." << endl;
        numMonkey--;
        break;
      case 2: /* seaOtter */
      cout << "The sick animal is a Sea Otter." << endl;
        numSeaOtter--;
        break;
      case 3: /* sloth */
      cout << "The sick animal is a Sloth." << endl;
        numSloth--;
        break;
    }
    numAnimals--;
    cout << "You couldn't afford to keep it alive. It dies, sorry." << endl << endl;
  }
}

void Zoo::makeBirth(){
  Animal* randAnimal = getRandAnimal();
  while(randAnimal->getAge() < 1095){
    randAnimal = getRandAnimal();
  }
  /* now that we have an adult animal */
  int type = randAnimal->getNumBabies();
  for(int i = 0; i < type; i++){
    switch(type){
      case 1: /* Monkey */
        cout << "Congratulations! One of your Monkeys gave birth!" << endl;
        addMonkey(0);
        break;
      case 2: /* SeaOtter */
        cout << "Congratulations! One of your Sea Otters gave birth!" << endl;
        addSeaOtter(0);
        break;
      case 3: /* Sloth */
        cout << "Congratulations! One of your Sloths gave birth!" << endl;
        addSloth(0);
        break;
    }
  }
  cout << endl;
}

void Zoo::makeBoom(){
  cout << "There's a Boom in Zoo attendance!" << endl;
  int bonus;
  for(int i = 0; i < numMonkey; i++){
    bonus = rand() % 251 + 250; /* random bonus */
    cout << "Monkey Bonus: " << bonus << endl;
    bankAccount += bonus;
  }
  cout << endl;
}

void Zoo::specialEvent(){
  int event = rand() % 4 + 1;
  cout << "SPECIAL EVENT: " << endl;

  switch(event){
    case 1:
      makeSick();
      break;
    case 2:
      makeBirth();
      break;
    case 3:
      makeBoom();
      break;
    case 4:
      cout << "No special event today!" << endl << endl;
  }
}

void Zoo::makeRevenue(){
  cout << "You earned revenue for each of your animals!" << endl;
  /* monkey revenue */
  for(int i = 0; i < numMonkey; i++){
    if(monkeys[i].getAge() < 30){
      bankAccount += (monkeys[i].getRevenue() * 2);
    } else {
      bankAccount += monkeys[i].getRevenue();
    }
  }
  /* sea otter revenue */
  for(int i = 0; i < numSeaOtter; i++){
    if(seaOtters[i].getAge() < 30){
      bankAccount += (seaOtters[i].getRevenue() * 2);
    } else {
      bankAccount += seaOtters[i].getRevenue();
    }
  }
  /* sloth revenue */
  for(int i = 0; i < numSloth; i++){
    if(sloths[i].getAge() < 30){
      bankAccount += (sloths[i].getRevenue() * 2);
    } else {
      bankAccount += sloths[i].getRevenue();
    }
  }
}

void Zoo::beginGame(){
  srand(time(NULL));
  int count = 0; /* days */
  int again = 1; /* play again */
  while(!bankrupt && again == 1){
    cout << endl << endl << "DAY " << count + 1 << endl << endl;
    displayGame();
    ageAnimals();
    buyAnimal();
    if(bankrupt) break; /*check for bankrupcy */
    feedAnimals();
    if(bankrupt) break;
    specialEvent();
    if(bankrupt) break;
    makeRevenue();
    count++;
    cout << endl << "Do you really want to keep playing?" << endl;
    again = checkInput("Enter 1(Yes) or 2(No): ", "12");
  }
  if(bankrupt){
    cout << "Your zoo went bankrupt :( Game Over." << endl;
  }
}

void Zoo::ageAnimals(){
  /* increment monkey age */
  for(int i = 0; i < numMonkey; i++){
    monkeys[i].incrementAge();
  }
  /* increment seaOtter age */
  for(int i = 0; i < numSeaOtter; i++){
    seaOtters[i].incrementAge();
  }
  /* increment sloth age */
  for(int i = 0; i < numSloth; i++){
    sloths[i].incrementAge();
  }

}

int Zoo::checkInput(string question, string valid){
   string var_str;
   size_t found;

   do{
      cout << question << endl;
      cin >> var_str;
      found = var_str.find_first_not_of(valid);
   }
   while(found != string::npos && var_str.length() < 2);

   return stoi(var_str);
}

int main(){
  Zoo zoo;
  zoo.beginGame();
}
