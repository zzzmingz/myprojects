/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.CowsAndBulls;

/**
 *
 * @author alfon
 */

import java.util.Scanner;

class CowsAndBulls {
	private static String chosenNum = "";
	private static void printWelcomeMessage() {
		System.out.println("WELCOME TO COWS AND BULLS!");
		System.out.println("The objective in this game is for you to guess a 4-digit number.");
                System.out.println();
                System.out.println("First, lets play rock, paper, scissors!");
	}
        
    private static void rockPaperScissors(){
      int PlayerOne, PlayerTwo, rock, paper, scissors;
      Scanner input = new Scanner (System.in);
      
      rock = 0;
      paper = 1;
      scissors = 2;

      System.out.println("0 for rock, 1 for paper, 2 for scissors");
      System.out.println();
      System.out.println("Player one please enter your choice:");
      PlayerOne = input.nextInt();
              while (PlayerOne > 2) {
            System.out.println("Give number between 0 and 2");
            PlayerOne = input.nextInt();
        }

      System.out.println("Player two please enter your choice:");
      PlayerTwo = input.nextInt();
      
      while (PlayerOne == PlayerTwo){
            System.out.println();
            System.out.println("DRAW, please try again!");
            System.out.println("Player one please enter your choice:");
            PlayerOne = input.nextInt();
                        while (PlayerOne > 2) {
                            System.out.println("Give number between 0 and 2");
                            PlayerOne = input.nextInt();
                            }
            System.out.println("Player two please enter your choice:");
            PlayerTwo = input.nextInt();
            } 
      
      if (PlayerTwo == rock)
        {
            if (PlayerOne == paper){  
                System.out.println("PLAYER ONE WINS!");
            } else { 
                System.out.println("PLAYER TWO WINS!");
            }
        }
      else if (PlayerTwo == paper)
      {
        if (PlayerOne == rock){ 
                System.out.println("PLAYER TWO WINS!");
            } else { 
                System.out.println("PLAYER ONE WINS!");
            }
        
      } else if (PlayerOne == rock){ 
                System.out.println("PLAYER ONE WINS!");
            } else {
                System.out.println("PLAYER TWO WINS!");
            } 
    }
    
    
    private static String TargetNumber() {
	chosenNum = "3107";
	while (nonDigitChecker(chosenNum)) {
            TargetNumber();
		}
	return chosenNum;
	}
        
    
    private static boolean nonDigitChecker(String num) {
	if (!num.matches("[0-9]")) {
			return true;
		}
            return false;
	}

    private static int computeBulls(String num1, String num2) {
	int bullCounter = 0;
            for (int i = 0; i < num1.length(); i++) {
            if (num1.charAt(i) == num2.charAt(i)) {
		bullCounter++;
			}
		}
            return bullCounter;
	}
        
    private static int computeCows(String num1, String num2) {
	int cowsCounter = 0;
	for (int i = 0; i < num1.length(); i++) {
            for (int j = 0; j < num2.length(); j++) {
		if (i != j) {
                    if (num1.charAt(i) == num2.charAt(j)) {
			cowsCounter++;
					}
				}
			}
		}
            return cowsCounter;
	}
        
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        printWelcomeMessage();
        rockPaperScissors();
	TargetNumber();
	int bulls = 0;
	int cows = 0;
	int guesses = 1;
	boolean notFound = true;
	while (notFound) {
            System.out.println();
            System.out.print("Enter guess number " + guesses + ": ");
            String guessedNumber = sc.nextLine();
            bulls = computeBulls(guessedNumber, chosenNum);
            cows = computeCows(guessedNumber, chosenNum);
                if (guesses >= 10) {
                    System.out.println("Bulls = " + bulls + "\tCows = " + cows);
                    System.out.println("NICE TRY!!! Sorry, You ran out of guesses.");
                    System.out.println("The correct number was: " + chosenNum);
                    notFound = false;
			} else if (guessedNumber.length() != 4) {
				System.out.println("Your guess should contain 4 symbols (Digits)");
			} else if (nonDigitChecker(guessedNumber)) {
				System.out.println("Your guess should not contain non-digits.");
			} else if (bulls == 4) {
				System.out.println("Bulls = " + bulls + "\tCows = " + cows);
				System.out.println("Congratulations! You won with " + guesses + " guesses.");
				notFound = false;
			} else if (!nonDigitChecker(guessedNumber)) {
				System.out.println("Bulls = " + bulls + "\tCows = " + cows);
				guesses++;
			}
		}
		sc.close();
	}
}
