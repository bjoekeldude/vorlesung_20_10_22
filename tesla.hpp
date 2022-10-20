#include<iostream>
#include<string>

enum model_t{
    S,
    E,
    X,
    Y,
    invalid
};

struct tesla_t{
private:
    float sprint; //Dauer von 0-100
    int reichweite; //Reichweite in km
    model_t model;

    void setConfig(int variante, model_t model_inp){
        model = model_inp;
        switch (variante)
        {
            case 1:
                if ( model == S ){
                    sprint      = 3.2;
                    reichweite  = 652;
                }
                else if ( model == E ){
                    sprint      = 6.1;
                    reichweite  = 491;
                } 
                else if ( model == X ){
                    sprint      = 3.9;
                    reichweite  = 580;
                }
                else if ( model == Y ){
                    sprint      = 5.0;
                    reichweite  = 533;
                };
                break;
            case 2: 
                if ( model == S ){
                    sprint      = 2.1;
                    reichweite  = 600;
                }
                else if ( model == E ){
                    sprint      = 3.3;
                    reichweite  = 547;
                }
                else if ( model == X ){
                    sprint      = 2.6;
                    reichweite  = 528;
                }
                else if ( model == Y ){
                    sprint      = 3.7;
                    reichweite  = 514;
                };
                break;
            case 3: 
                if ( model == E ){
                    sprint      = 4.4;
                    reichweite  = 602;
                };
                break;
            default:  
                std::cerr << "Corrupted Data in setConfig" << std::endl;
                std::abort();
        }
    };

    std::string getModelstring(){
        std::string retval{};
        
        if      ( model == S ) retval = "S";
        else if ( model == E ) retval = "3";
        else if ( model == X ) retval = "X";
        else if ( model == Y ) retval = "Y";

        return retval;
    }

public:
    tesla_t(){
        model_t model_inp{};
        int variante_inp{};
        while(true){
            char input{};
            std::cout << "Welches Fahrzeug soll es sein?" << std::endl << "(S/3/X/Y)? ";
            std::cin >> input;
            
            switch ( input )
            {
            case 's':
            case 'S': model_inp = S;                        break;
            case '3':
            case 'E':
            case 'e': model_inp = E;                        break;
            case 'x':
            case 'X': model_inp = X;                        break;
            case 'y':
            case 'Y': model_inp = Y;                        break;
            default:  model_inp = invalid;                  break;
            };
            if(model_inp != invalid) break;
            std::cout << "Keine Gültige Eingabe - bitte Modell wählen!" << std::endl;
        }

        while(true){
            bool isValid{false};
            char input{};

            std::cout << "Welche Variante?"     << std::endl
                      << "(1) Standard"         << std::endl
                      << "(2) Performance/Plaid"<< std::endl;
            if( model == E ) std::cout << "(3) Long Range" << std::endl;

            std::cout << "Ihre Auswahl: ";
            std::cin >> input;

            switch (input)
            {
                case '1':
                    isValid = true;
                    variante_inp = 1;
                    break;
                
                case '2':                   
                    isValid = true;
                    variante_inp = 2;
                    break;
                
                case '3': 
                    if( model == E ){
                    isValid = true;
                    variante_inp = 3; 
                    }
                    break;            
                
                default: 
                    std::cout << "Ungültige Eingabe!" << std::endl;    
                    break;
            }
            if(!isValid) continue;
            setConfig(variante_inp, model_inp);
            break;
        }


    };
    std::string getInfo(){
        std::string retval{};

        std::string teil1{"Das Modell "};
        std::string teil2{" sprintet in "};
        std::string teil3{" s von 0 auf 100 km/h. Seine Reichweite beträgt "};
        std::string teil4{" km."};

        retval = teil1 + getModelstring() + teil2 + std::to_string(sprint) 
                        + teil3 + std::to_string(reichweite) + teil4;
        return retval;
    }
};