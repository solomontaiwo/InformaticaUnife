import java.util.Scanner;

class sumInt {
    static int sum(int a, int b) {
        return a + b;
    }

    public static void main(String args[]) {
        Scanner readNumbers = new Scanner(System.in);
        int number1 = readNumbers.nextInt();
        int number2 = readNumbers.nextInt();

        System.out.println("La somma dei numeri da te inseriti e' pari a " + sum(number1, number2) + ".");

        readNumbers.close();
    }
}