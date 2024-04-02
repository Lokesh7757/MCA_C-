import java.util.*;

class Player {
    String name;
    int age;

    Player(String name, int age) {
        this.name = name;
        this.age = age;

    }

    void Display() {
        System.out.println("Name Of The Player :" + name);

        System.out.println(" Age Of The Player:" + age);

    }
}

class cricket extends Player {
    String team;

    cricket(String name, int age, String team) {
        super(name, age);
        this.team = team;
    }

    void Dispaly() {
        super.Display();
        System.out.println("Team of player is:" + team);

    }
}

class Football extends Player {
    String club;

    Football(String name, int age, String club) {
        super(name, age);
        this.club = club;
    }

    void Display() {
        super.Display();
        System.out.println("Cluab of player is " + club);
    }
}

class Hockey extends Player {
    String Nation;

    Hockey(String name, int age, String Nation) {
        super(name, age);
        this.Nation = Nation;

    }

    void Dispaly() {
        super.Display();
        System.out.println("The Nation is:" + Nation);
    }

}

public class main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        cricket c1 = new cricket("Dhoni", 7, "India");
        Football f1 = new Football("Viart", 18, "India");
        Hockey h1 = new Hockey("Rohit", 32, "India");

        System.out.println("Cricket Player");
        c1.Dispaly();
        System.out.println("Football Player");
        f1.Display();
        System.out.println("Hockey player");
        h1.Dispaly();
    }
}
