import java.util.Scanner;
import java.lang.Math;

public class Main {
    private static Scanner sc = new Scanner(System.in);

    // Main function to start the program
    public static void main(String[] args) {
        play();
    }

    // Function to simulate the game
    private static void play() {
        String shipName = intro();
        {
            System.out.println("You are an officer (Gun calculator office) on the board of " + shipName);
            System.out.println("Today is 1916 May 31th");
            System.out.println("In the future, peoples call this day \"The day of dark\", wellcome to the Battle of Jutland.");
            System.out.println();
        }

        {
            System.out.println("Will you start? [Y]es, [N]0");
            System.out.println();
            String response = sc.nextLine().toLowerCase();
            if (response.charAt(0) == 'y') {
                System.out.println("Move your ass! Go to the commander tower.");
            } else {
                System.out.println("So sad, you have already on the board!");

                try {
                    Thread.sleep(800);
                } catch (InterruptedException e) {}

                System.out.println("Wait !!!!!!!");

                try {
                    Thread.sleep(800);
                } catch (InterruptedException e) {}

                System.out.println("ENEMY ON THE LEFT SIDE !!!!!! GERMAN SMS Derfflinger\n MOVE TO THE COMMANDER TOWER");
            }
        }

        displayAsciiBattle(shipName);

        int userHp = 10000 + (int) (Math.random() * 10000),
                enemyHP = 12000 + (int) (Math.random() * 12000);

        while (userHp > 0 && enemyHP > 0) {
            System.out.println();
            System.out.println();
            System.out.println(shipName + " HP: " + userHp + " .........   GERMAN SMS Derfflinger HP: " + enemyHP);
            System.out.println();
            printBattleLine();

            double[][] matrix = new double[3][4];
            generateRandomSystem(matrix);

            System.out.println("Solve the system: If no solution, enter all -1. If infinite solutions, enter all -2.");
            System.out.println();
            printSystem(matrix);

            double[] userInput = new double[3];
            System.out.print("Input the answer like this: x1 x2 x3 (Remember to round down)\n");
            for (int i = 0; i < 3; i++) {
                userInput[i] = sc.nextDouble();
            }

            System.out.println();

            double[] solution = gaussElimination(matrix);

            if (solution[0] == -10000 && allEqual(userInput, -1)) {
                System.out.println("Correct! The system has no solution.");
            } else if (solution[0] == -100100 && allEqual(userInput, -2)) {
                System.out.println("Correct! The system has infinite solutions.");
            } else if (solution[0] != -1 && solution[0] != -2) {
                boolean correct = true;
                for (int i = 0; i < 3; i++) {
                    if ((int) Math.floor(solution[i]) != (int) userInput[i]) {
                        correct = false;
                        break;
                    }
                }

                if (correct) {
                    System.out.println("Correct! You dealt massive damage to the enemy!");
                    int damage = (int)Math.random() * 8 + 1;
                    System.out.println("You hit " + damage + " 343 mm cannonball on the enemy.");
                    enemyHP -= damage * 400;
                    System.out.println("Enemy took " + damage + " damage!");
                } else {
                    System.out.println("Incorrect solution! You shot 8 343 canoonBalls into the water.");
                    System.out.println("The correct solution was: ("
                            + (int) Math.floor(solution[0]) + ", "
                            + (int) Math.floor(solution[1]) + ", "
                            + (int) Math.floor(solution[2]) + ")");
                }
            } else {
                System.out.println("Incorrect! The system has a special status. The machine need to reset. What a bad luck");
            }

            int enemyDamage = (int)(Math.random() * 10) + 1;
            System.out.println("Enemy hits " + enemyDamage + " 305 mm CannonBalls on your ship!");
            System.out.println("Enemy counterattacks, dealing " + enemyDamage * 290 + " damage!");
            userHp -= enemyDamage * 290;

            if (userHp <= 0 || enemyHP <= 0) break;
        }

        if (userHp <= 0) {
            System.out.println();
            System.out.println("Oh! Your ship has been sunk!");
        } else if (enemyHP <= 0) {
            System.out.println();
            System.out.println("Victory! The enemy ship has been destroyed!");
        }
    }

    private static boolean allEqual(double[] array, double value) {
        for (double num : array) {
            if (num != value) {
                return false;
            }
        }
        return true;
    }

    private static void generateRandomSystem(double[][] matrix) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                matrix[i][j] = (int) (Math.random() * 10) + 1;
            }
        }
    }

    private static void printSystem(double[][] matrix) {
        String[] variables = {"x", "y", "z"};
        for (int i = 0; i < 3; i++) {
            System.out.print((int) matrix[i][0] + variables[0]);
            for (int j = 1; j < 3; j++) {
                System.out.print(" + " + (int) matrix[i][j] + variables[j]);
            }
            System.out.println(" = " + (int) matrix[i][3]);
        }
    }

    private static void displayAsciiBattle(String shipName) {
        System.out.println();
        System.out.println("Battle Scene:");
        System.out.println("---------------------------------------------------------");
        System.out.println("         . . . .       ~~~~  ~~~~        . . . .         ");
        System.out.println("       .         .       HMS Fleet        .         .    ");
        System.out.println("     .     " + shipName + "     .                .     Battlecruisers ");
        System.out.println("---------------------------------------------------------");
        System.out.println("                 . . . .       Enemy Fleet       . . . .  ");
        System.out.println("             .   German Dreadnoughts       .             ");
        System.out.println("         .        German Light Cruisers          .        ");
        System.out.println("     .               ~~~~   ~~~~                     .    ");
        System.out.println("---------------------------------------------------------");
    }

    private static String intro() {
        String shipName = getRandomBattleCruiser();
        System.out.println("Welcome aboard HMS " + shipName + "!");
        System.out.println("Your mission is to defeat the German fleet using your skills.");
        return shipName;
    }

    private static String getRandomBattleCruiser() {
        String[] ships = {"HMS Lion", "HMS Queen Mary", "HMS Tiger", "HMS Princess Royal"};
        return ships[(int) (Math.random() * ships.length)];
    }

    private static void printBattleLine() {
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }

    public static double[] gaussElimination(double[][] matrix) {
        int n = matrix.length;

        for (int i = 0; i < n; i++) {
            // Pivoting: Ensure the diagonal element is non-zero
            if (Math.abs(matrix[i][i]) < 1e-9) {
                boolean pivotFound = false;
                for (int k = i + 1; k < n; k++) {
                    if (Math.abs(matrix[k][i]) > 1e-9) {
                        double[] temp = matrix[i];
                        matrix[i] = matrix[k];
                        matrix[k] = temp;
                        pivotFound = true;
                        break;
                    }
                }
                if (!pivotFound) {
                    // Check for infinite solutions or no solutions
                    boolean allZero = true;
                    for (int j = i; j < n; j++) {
                        if (Math.abs(matrix[i][j]) > 1e-9) {
                            allZero = false;
                            break;
                        }
                    }
                    if (allZero && Math.abs(matrix[i][n]) > 1e-9) {
                        return createArray(n, -10000); // No solution
                    } else if (allZero) {
                        return createArray(n, -100100); // Infinite solutions
                    }
                }
            }

            // Eliminate below the pivot
            for (int k = i + 1; k < n; k++) {
                double factor = matrix[k][i] / matrix[i][i];
                for (int j = i; j <= n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }

        // Back substitution to find the solution
        double[] solution = new double[n];
        for (int i = n - 1; i >= 0; i--) {
            solution[i] = matrix[i][n];
            for (int j = i + 1; j < n; j++) {
                solution[i] -= matrix[i][j] * solution[j];
            }
            if (Math.abs(matrix[i][i]) < 1e-9) {
                return createArray(n, -100100); // Infinite solutions
            }
            solution[i] /= matrix[i][i];
        }
        return solution;
    }

    // Helper method to create an array filled with a specific value
    private static double[] createArray(int size, double value) {
        double[] array = new double[size];
        for (int i = 0; i < size; i++) {
            array[i] = value;
        }
        return array;
    }

}
