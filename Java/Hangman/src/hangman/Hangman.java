/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author BlueZ
 */
public class Hangman {
    
    public Hangman() {
        System.out.println("Welcome to Hangman!");
        System.out.println("Please enter CAPITAL letters ONLY.");
        System.out.println("----------------------------------");
    }
    
    public boolean revealWord(String theWord, int[] showState, String guess) { 
        int checkFound = 0;        
        for(int i = 0; i < theWord.length(); i++) {     //if letter is found, update the show state
            if(guess.equals(theWord.substring(i,i+1))) {
                showState[i] = 1;       
                checkFound++;
            }
        }
        System.out.print("\n");
        for(int i = 0; i < theWord.length(); i++) {     //reveal the found letters
            if(showState[i] == 1) {         
                System.out.print(theWord.substring(i,i+1) + " ");
            }
            else {
                System.out.print("_ ");
            }
        }
        System.out.println("\n\n----------------------------------");
        if(checkFound == 0) {       //if the letter is not found in the word
            return false;
        }
        else return true;
    }
    
    public void info(String[] wrongLetters, int limbs) {
        System.out.println("Limbs remaining: " + limbs);
        System.out.print("Incorrect guesses: ");
        for (String wrongLetter : wrongLetters) {       //shows all the incorrect guesses
            if(wrongLetter != null) {
                System.out.print(wrongLetter + " ");
            }
        }
        System.out.print("\n");
    }
    
    public boolean didPlayerWin(int[] showState) {     
        for(int i = 0; i < showState.length; i++) {
            if(showState[i] != 1) return false;
        }
        return true;        //wins only if all the show states are set to 1
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String choice = "Y";
        String[] words = { "ELEPHANT", "PARROT", "TIGER", "CHEETAH", "EAGLE", "HORSE", "BUTTERFLY", "WHALE", "MONKEY", "HUMAN", "RABBIT", "PIGEON" };
        int limbs;     
        String guess;   
        boolean found;
        Hangman game = new Hangman();
        Random random;
        int index; 
        String theWord;                 //the randomly selected word 
        int[] showState;                //keeps track of correct letters
        String[] wrongLetters;          //stores the incorrect letters
        Scanner in = new Scanner(System.in);
        
        while(choice.equals("Y")) {
            
            System.out.println("Your word is: ");       
            limbs = 6;                                  //initializing variables for a new game
            guess = " ";
            wrongLetters = new String[40];
            random = new Random();
            index = random.nextInt(words.length);
            theWord = words[index];
            showState = new int[theWord.length()];
            showState[0] = 0;
            
            for(int i = 0; true;) {
                found = game.revealWord(theWord, showState, guess);
                if(game.didPlayerWin(showState)) {      //winning condition
                    System.out.println("You Win!");
                    break;
                }
                if(found == false) {        //if letter not found in the word
                    limbs--;
                    wrongLetters[i] = guess;
                    if(!guess.equals(" ")) i++;
                }
                if(limbs == 0) {            //loosing condition
                    System.out.println("Sorry, you Lose!");
                    System.out.println("The word was: " + theWord);
                    break;
                }
                game.info(wrongLetters, limbs);
                System.out.print("Guess a letter: ");
                guess = in.next();
            }
            
            System.out.print("\nDo you want to play again?(Y/N): ");
            choice = in.next();
        }   
    }  
}
