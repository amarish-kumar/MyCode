/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tictactoe;
import java.util.Scanner;

/**
 *
 * @author BlueZ
 */
public class TicTacToe {
    
    String p1, p2;
    
    public TicTacToe() {
        Scanner in = new Scanner(System.in);
        System.out.println("Tic-Tac-Toe!");
        System.out.println("This is a new game.");
        System.out.print("Enter Player-1 name: ");
        p1 = in.next();
        System.out.print("Enter Player-2 name: ");
        p2 = in.next();
        System.out.println(p1 + " is X and " + p2 + " is O.");
        System.out.println("The positions which you can select are numbered as follows: ");
        int count = 0;
        for(int i = 0; i < 3; i++) {
           System.out.print("\n\t");
           for(int j = 0; j < 3; j++) {
               count++;
               System.out.print(count);
               if(j != 2) {
                   System.out.print(" | ");
               }
           } 
        }
    }
    
    public void showBoard(int[][] board) {
        for(int i = 0; i < 3; i++) {
            System.out.print("\n\t");
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 1) {      //1 for Player-1
                    System.out.print("X");
                }
                if(board[i][j] == 2) {      //2 for Player-2
                    System.out.print("O");
                }
                if(board[i][j] == 0) {      //empty position
                    System.out.print(" ");
                }
                if(j != 2) {
                    System.out.print(" | ");
                }
            }
        }
    }
    
    public void updateBoard(int[][] board, int pos, int who) {      //function to update board
        int count = 0;      //keeps track of the position
        for(int i = 0; i < 3; i++) {
           for(int j = 0; j < 3; j++) {
               count++;
               if(count == pos) {
                   if(board[i][j] == 0) {
                       if(who == 1) {       //for player-1
                           board[i][j] = 1;
                           break;
                       }
                       else {               //for player-2
                           board[i][j] = 2;
                           break;
                       }
                   }
                   else {                   //if position is already taken
                       System.out.println("\nInvalid Choice!");
                       Scanner in = new Scanner(System.in);
                       System.out.print("Enter a valid position: ");
                       int newPos = in.nextInt();
                       this.updateBoard(board, newPos, who);
                       break;
                   }
               }
           } 
        }
    }
    
    public int decideWinner(int[][] board) {        //sorry, this is all I could think of
        int d11, d12, d21, d22, r1, r2, c1, c2, a = 0;
        d11 = d12 = d21 = d22 = r1 = r2 = c1 = c2 = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 0) a++;
                if(i == j) {
                    if(board[i][j] == 1) d11++;
                    if(board[i][j] == 2) d12++;
                    if(d11 == 3) return 1;
                    if(d12 == 3) return 2;
                }
                if(i + j == 2) {
                    if(board[i][j] == 1) d21++;
                    if(board[i][j] == 2) d22++;
                    if(d21 == 3) return 1;
                    if(d22 == 3) return 2; 
                }
                if(board[i][j] == 1) r1++;
                if(board[i][j] == 2) r2++;
                if(r1 == 3) return 1;
                if(r2 == 3) return 2;
                if(board[j][i] == 1) c1++;
                if(board[j][i] == 2) c2++;
                if(c1 == 3) return 1;
                if(c2 == 3) return 2;
            }
            r1 = r2 = c1 = c2 = 0;
        }
        if(a == 0) return -1;       //when whole board is filled
        return 0;                   //default condition
    }
    

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        TicTacToe game = new TicTacToe();
        String ch = "y";
        while("y".equals(ch)) {
            Scanner in = new Scanner(System.in);
            int pos1, pos2;
            int winner = 0;     
            int[][] board = { {0,0,0}, {0,0,0}, {0,0,0} };
            while(winner == 0) {        //until no winner is found
                System.out.print("\n\n" + game.p1 + ", enter your position: ");
                pos1 = in.nextInt();
                game.updateBoard(board, pos1, 1);
                game.showBoard(board);
                winner = game.decideWinner(board); 
                if(winner != 0 ) break;
                System.out.print("\n\n" + game.p2 + ", enter your position: ");
                pos2 = in.nextInt();
                game.updateBoard(board, pos2, 2);
                game.showBoard(board);
                winner = game.decideWinner(board);
            }
            switch (winner) {
                case 1:
                    System.out.println("\n\n" + game.p1 + " is the winner!");
                    break;
                case 2:
                    System.out.println("\n\n" + game.p2 + " is the winner!");
                    break;
                default:
                    System.out.println("\n\nIt is a tie.");
                    break;
            }
            System.out.print("\n\nDo you want to play a new game(y/n): ");
            ch = in.next();
        }
    }   
}
