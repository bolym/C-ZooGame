#include "zoo.hpp"

/******************************************************************
 * Function: Zoo()
 * Description: Default Zoo constructor that sets the private
                variables to their initial values
 * Parameters: None
 * Pre-Conditions: The class itself has already called the constructor
                    for the other private variables
 * Post-Conditions: The zoo game begins as not over
******************************************************************/
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

/******************************************************************
 * Function: ~Zoo()
 * Description: Destructor that deletes the dynamically created
                array of differnt animals
 * Parameters: None
 * Pre-Conditions: animal arrays must be instantiated
 * Post-Conditions: animal arrays are deleted
******************************************************************/
Zoo::~Zoo(){
  delete[] monkeys;
  delete[] seaOtters;
  delete[] sloths;
}

/******************************************************************
 * Function: displayGame()
 * Description: displays for the user the current status of the game
                by showing their balance and animals in the zoo
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
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

/******************************************************************
 * Function: ageAnimals()
 * Description: increment the age of each animal by 1
 * Parameters: None
 * Pre-Conditions: animal arrays must be instantiated
 * Post-Conditions: each animal's age increased by 1
******************************************************************/
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

/******************************************************************
 * Function: addMonkey()
 * Description: adds a monkey to the array of monkeys in the zoo
                and resizes the array
 * Parameters: int age
 * Pre-Conditions: monkeys has been initialized
 * Post-Conditions: monkeys contains another monkey
******************************************************************/
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

/******************************************************************
 * Function: addSeaOtter()
 * Description: adds a seaOtter to the array of seaOtters in the zoo
                and resizes the array
 * Parameters: int age
 * Pre-Conditions: seaOtters has been initialized
 * Post-Conditions: seaOtters contains another seaOtter
******************************************************************/
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

/******************************************************************
 * Function: addSloth()
 * Description: adds a sloth to the array of sloths in the zoo
                and resizes the array
 * Parameters: int age
 * Pre-Conditions: sloths has been initialized
 * Post-Conditions: sloths contains another sloth
******************************************************************/
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

/******************************************************************
 * Function: buyAnimal()
 * Description: "buys" animals of the user's choosing by getting
                user input
 * Parameters: None
 * Pre-Conditions: animal arrays must be initialized
 * Post-Conditions: maybe another animal(s) is added to the zoo
******************************************************************/
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

/******************************************************************
 * Function: feedAnimals()
 * Description: Calculates the food cost for each animal and subtracts
                it from the bankAccount, calculates new base cost
 * Parameters: None
 * Pre-Conditions: animal arrays must be initialized
 * Post-Conditions: bankAccount has less money
******************************************************************/
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

/******************************************************************
 * Function: getRandAnimal()
 * Description: Returns a pointer to a random animal in the zoo
 * Parameters: None
 * Pre-Conditions: animal arrays must be initialized
 * Post-Conditions: none of the animal arrays change
******************************************************************/
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

/******************************************************************
 * Function: makeSick()
 * Description: makes user pay for random sick animal, or it dies
                and is removed from its array
 * Parameters: None
 * Pre-Conditions: animal arrays must be initialized
 * Post-Conditions: maybe an animal array looses an animal
******************************************************************/
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

/******************************************************************
 * Function: makeBirth()
 * Description: adds new animals to the randomly chosen animal's
                array based on their numBabies
 * Parameters: None
 * Pre-Conditions: animal arrays must be initialized
 * Post-Conditions: numBabies animals are added to its array
******************************************************************/
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

/******************************************************************
 * Function: makeBoom()
 * Description: adds monkey bonuses for zoo boom
 * Parameters: None
 * Pre-Conditions: monkeys array must be initialized
 * Post-Conditions: bankAccount has more money
******************************************************************/
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

/******************************************************************
 * Function: specialEvent()
 * Description: randomly chooses special event for that day
 * Parameters: None
 * Pre-Conditions: animal arrays must be initialized
 * Post-Conditions: animal arrays don't change
******************************************************************/
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

/******************************************************************
 * Function: makeRevenue()
 * Description: adds revenue for each animal to the bankAccount
 * Parameters: None
 * Pre-Conditions: animal arrays must be initialized
 * Post-Conditions: bankAccount has more money
******************************************************************/
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

/******************************************************************
 * Function: checkInput
 * Description: Performs a do-while using question to only accept
 * 		characters that are in valid. Returns integer
 * 		version of input.
 * Parameters: string question, string valid
 * Pre-Conditions: question and valid must not be empty
 * Post-Conditions: question and valid don't change
******************************************************************/
int Zoo::checkInput(string question, string valid){
   string var_str;
   size_t found;

   do{
      cout << question << endl;
      cin >> var_str;
      found = var_str.find_first_not_of(valid);
   }
   while(found != string::npos);

   return stoi(var_str);
}

/******************************************************************
 * Function: beginGame()
 * Description: runs through the structure of a day in the zoo until
                the user chooses to quit or goes bankrupt
 * Parameters: None
 * Pre-Conditions: animal arrays must be initialized
 * Post-Conditions: the game has ended
******************************************************************/
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
    //specialEvent();
    makeSick();
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
