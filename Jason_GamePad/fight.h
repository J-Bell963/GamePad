// Check to See if Hero & Enemies Collide
boolean checkCollide(int hX, int hY, int hW, int hH, int eX, int eY, int eW, int eH){
  boolean canMove = false;           // Assume a move can be made
  boolean xMin = false; if(hX < eX + eW){xMin = true;}               // Does the xMin collide?
  boolean xMax = false; if(hX + hW > eX){xMax = true;}               // Does the xMax collide?
  boolean yMin = false; if(hY < eY + eH){yMin = true;}               // Does the yMin collide?
  boolean yMax = false; if(hY + hH > eY){yMax = true;}               // Does the yMin collide?
  if (xMin && xMax && yMin && yMax) {canMove = true;}
  return canMove;
}



void fight() {
  boolean canFight = checkCollide(heroX, heroY, heroW, heroH, enemyX, enemyY, enemyW, enemyH); //takes in the hero and enemy location
  if (canFight == true) {
    if (buttonBuffer[1] == 1) {//right attack
      enemyHealth = enemyHealth - 1;
    }
    if (buttonBuffer[3] == 1) {//left attack
      enemyHealth = enemyHealth - 1;
    }

    if (enemyHealth == 0) {//removes a dead enemy from screen
      enemyStatus = false;
      enemyX = 1000;
      enemyY = 1000;
    }
     if (random(75) == 0) { // chance of hero taking damage when enemy is within range
      heroHealth = heroHealth - 1;
    }
    if (heroHealth == 0) { // if the hero has no health, pulls up death screen
      curMode = -2;
    }
  }
  //Serial.println(heroHealth);
}
