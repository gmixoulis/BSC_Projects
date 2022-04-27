import java.util.Scanner;

import java.util.Random;















public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

       
        
        //40 fylla, Asoi = 11, oi Asoi dn mporoun na metatrapoun se 1, lypoun  ta symvola ( Q,J,K)
        int[] Deck = {2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11};

        
        
        
        
        //Anakatema mia fora kathe paixnidi.
        MixTheDeck(Deck);
        //Enarksh BlackJack.
        System.out.println("Welcome to the simplified BlackJack game!");
        System.out.println("You get a " + Deck[0] + " and a " + Deck[1] + ".");
        
        int Gamer = Deck[0] + Deck[1];
        System.out.println("Your total is " + Gamer + ".");
        System.out.println("---------------");

/*o paikths mporei apo ton prwto gyro na exei kerdisei h kai na exei xasei 
        opote to elegxoume se periptwsh p kerdise h kai exase */
        if (Gamer == 21){
            System.out.println("YOU WIN");
            System.exit(0);
        }
        else if (Gamer > 21){
            System.out.println("YOU LOST.");
            System.exit(0);
        }
     
        
        
        // Dealer cards
      
        
        
        System.out.println("The dealer has a " + Deck[2] + " showing, and a hidden card.");
        int Dealer = Deck[2] + Deck[3];
        if (Dealer > 21){     //Petiprwsh p o dealer exase me to 2o xarti.
            System.out.println();
            System.out.println("Dealer total is " + Dealer);
            System.out.println("YOU WIN!");
            System.exit(0);
        }
        else if (Dealer == 21){    //Dealer nikhse me to 2o xarti.
            System.out.println();
            System.out.println("Dealer reveals his second card: " + Deck[3]);
            System.out.println("Dealer total is " + Dealer );
            System.out.println("DEALER WINS");
            System.exit(0);
        }
        // Hit or Stay for player.
        System.out.print("Would you like to \"hit\" or \"stay\"? ");
        String StayOrHit = in.next();
        System.out.println("------------------");

        //s = athrisths
        int s = 4; 
        if (StayOrHit != "hit"){
            while (Gamer < 21 && StayOrHit.equals("hit")){
                if (StayOrHit.equals("hit")){
                    System.out.println("You drew a " + Deck[s] + ".");
                    Gamer = Gamer + Deck[s];
                    System.out.println("Your total is " + Gamer + ".");
                    System.out.println();
                    s++;        // ayksanete o athrisths wste na alaksei kai to epomeno xarti
                    if (Gamer > 21){
                        System.out.println("YOU LOST.");
                        System.exit(0);
                    }
                    else if (Gamer == 21){
                        System.out.println("YOU WIN .");
                        System.exit(0);
                    }
                    System.out.print("Would you like to \"hit\" or \"stay\"? ");
                    StayOrHit = in.next();
                    System.out.println("-----------");
                }
            }        
        }

// h seira tou Dealer se periptwsh p patise 'stay' o paikths
        
        in.close();
        System.out.println("Ok dealers turn.");
        System.out.println("His hidden card was a " + Deck[3] + "."); // Emfanish tou kryfou xartiou.

        while (Dealer < 16){ // o Dealer tha pathsei stay se periptwsh p to synolo tou einai megalytero iso tou 16.
            System.out.println("Dealer chooses to hit.");
            System.out.println("He draws a " + Deck[s] + ".");
            s++;
            Dealer = Dealer + Deck[s];
            System.out.println("----------");
            System.out.println("His total is " + Dealer);
            if (Dealer > 21){
                System.out.println("----------");
                System.out.println("YOU WIN!");
                System.exit(0);
            }
            if (Dealer < 21 && Dealer > 16){
                System.out.println("-----------");
                System.out.println("Dealer Stays.");
            }
        }

        // teleytaia sygkrish kartwn metaksy paikth kai dealer.
        System.out.println();
        System.out.println("Dealer total is " + Dealer +  "  Your total is " + Gamer);
        if (Dealer > Gamer){
            System.out.println("YOU LOST.");
        } 
        else if (Dealer == Gamer){
            System.out.println("You both draw.");
        }
        else {
            System.out.println("YOU WIN");
        }
    }

  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    static void MixTheDeck(int[] Deck){
        Random rand = new Random();
        for (int i = Deck.length; i > 0; i--)
        {
            int j = rand.nextInt(i + 1);// epilogh epomenou tyxaiou arithmou
            // enalagh
            int a = Deck[j];
            Deck[j] = Deck[i];
            Deck[i] = a;
        }
    }
}