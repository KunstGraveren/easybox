
<!-- <img align="right" width="50%" src="instructions-images/uselessbox-tr.png"> -->
<img align="right" width="50%" src="instructions-images/easybox-kg.png">

<!-- TOC -->

- [Onderdelen:](#onderdelen)
    - [Geprinte onderdelen:](#geprinte-onderdelen)
    - [Montage:](#montage)
    - [Electronica:](#electronica)
    - [Bekabeling:](#bekabeling)
    - [Tools:](#tools)
- [Voorbereiding:](#voorbereiding)
    - [Pin headers in de bodemplaat:](#pin-headers-in-de-bodemplaat)
    - [LCD:](#lcd)
    - [Hoek connectoren:](#hoek-connectoren)
    - [Top & Arcadeknop:](#top--arcadeknop)
    - [LED:](#led)
- [Solderen:](#solderen)
    - [Ver-tinnen:](#ver-tinnen)
    - [Bedrading Solderen aan de Arduino Nano:](#bedrading-solderen-aan-de-arduino-nano)
        - [Stap 0:](#stap-0)
        - [Stap 1: Zwart GND -> Schakelaar -> LED](#stap-1-zwart-gnd---schakelaar---led)
        - [Stap 2:](#stap-2-)
        - [Stap 3:](#stap-3)
        - [Stap 4:](#stap-4)
        - [Stap 4:](#stap-4)
        - [Stap 5:](#stap-5)
        - [Stap 6:](#stap-6)
    - [Arduino Nano Pinnen Solderen:](#arduino-nano-pinnen-solderen)
    - [LED Solderen aan de Arduino Nano:](#led-solderen-aan-de-arduino-nano)
    - [PowerOn](#poweron)
- [Montage:](#montage)
- [Code Uploaden:](#code-uploaden)

<!-- /TOC -->

# Onderdelen:

## Geprinte onderdelen: 

- 1x achterkant
- 1x voorkant
- 1x bodem
- 1x deksel
- 2x zijkant
- 1x lcd mount
- 1x lcd clip
- 2x 90 koppel connector ?
- 2x 270 koppel connector ?

- 1x event logo 

## Montage:

- 12x M3 x 6mm
- 8x M3 x 8mm 

## Electronica:

- 4x 2 pins header
- 1x LCD 7 segments - 6bit (TM1637)
- 1x Arduino Nano (USB-C)
- 1x WS2812B LED

## Bekabeling:

- 1x rood 40mm
- 2x rood 80mm
- 1x rood 100mm
    - totaal: 300mm
- 1x zwart 80mm
- 1x zwart 100mm
    - toaal: 180mm
- 1x groen 100mm
- 1x geel 100mm
     
## Tools:

- 1x M3 Inbus (2.5) 
- 1x Soldeerbout 
- 1x Tin 
- 1x Zijknip tang
- 1x Punt tang 

---

# 1. Voorbereiding: 

## **Pin headers in de bodemplaat:**
<img align="right" width="20%" src="instructions-images/bodem_pins.png">

Neem vier 2-pins connectoren en plaats deze in de buitenste hoeken van de bodemplaat. Zorg ervoor dat de korte uiteinden van de pinnen naar beneden gericht zijn, zodat ze stevig in de bodem kunnen worden bevestigd.

- Duw de pinnen voorzichtig naar beneden totdat ze gelijk zijn met de onderkant van de bodemplaat.

- Plaats de Arduino Nano op de pinnen


## **LCD:** 

- Schuif het LCD in de bracket.
    - `pas op!` het "zwarte" van de display is kras gevoelig.

    <img width="29.8%" src="instructions-images/montage-lcd-into-mount.png">

- Plaats de clip over de LCD heen, `onderkant eerst`, daarna klik je de bovenkant vast (ja.. dit gaat strak)

    <img width="25%" src="instructions-images/montage-lcd-into-mount-clip.png">
    --> 
    <img width="27.35%" src="instructions-images/montage-lcd-into-mount-finalpos.png">

- Plaats nu de voorkant, en bout deze met 4 boutjes vast.

    <img width="25%" src="instructions-images/montage-lcd-into-mount-front.png">
    <img width="30%" src="instructions-images/montage-lcd-into-mount-front-bouten.png">


## **Hoek connectoren:** 

  - monteer op de beide zijkanten de 2 benodigde connectoren. De connector met 2 gaten gaat onder (wit op het plaatje), en de connector met 3 gaten gaat boven (paars op het plaatje).

    note: de onderkant van de zijkant is, waar de "gleuf" zit.

    - (optie) plaats het event zijlogo in de zijkant voordat je deze vastschroeft.
    
    
    <img  width="25%" src="instructions-images/voorbereiding-connectors-zijkant.png">



        - Monteer de hoek connectors zijplaten. (voor achterplaat + bovenplaat)

        Let op dat er een boven- en onderkant is. Waar de gleuf zit is de onderkant van het paneel.

        - 2 connectoren aan de ene kant
        - 2 connectoren op de andere kant

        - Draai deze nog niet helemaal vast, maar zo dat de connector nog net kan bewegen.


## **Top & Arcadeknop:** 

  - Ontkoppel de arcadeknop. Draai `links-om` (kwartslag) om de arcadeknop behuiding en electronica te ontkoppelen.
    
    - let op de rode pijl, om te zien hoe de meganisme werkt
  
    <img  width="25%" src="instructions-images/voorbereiding-arcadeknop-ontkoppel.png">

  - Monteer de push button op de bovenplaat ( zonder switch/led )

    <img  width="25%" src="instructions-images/voorbereiding-arcadeknop.png">

  - Test nu er geen bedraging vast zit, hoe je de arcadeknop weer in elkaar draait, zodat straks bij montage het gemakkelijker gaat om deze weer erin terug te zetten.     

  - **[WIP]** De led kan uit de module die je zojuist hebt ontkoppeld...




## **LED:** 

- Buig de LED in de juiste vorm, zodat deze uitkomt bij de aangegeven pinnen. Gebruik hiervoor het punt tangetje.

  <img  width="40%" src="instructions-images/led-01.png">
  <img  width="50%" src="instructions-images/led-02.png">

  - **Vraag hulp indien nodig om ervoor te zorgen dat deze goed gepositioneerd / gebogen wordt.**

  - **Let op ze “platte zijde” van de led bij het plaatsen.**


---

# 2.Solderen:

## **Ver-tinnen:** 

Dit houdt in dat je een dunne laag soldeermetaal (tin) aanbrengt op de blootgestelde koperdraden om een betere verbinding te creëren als je ze soldeert.

**Bedraging:** 

<img align="right" width="20%" src="instructions-images/bedraging-vertinnen.png">

- Ver-tin de uiteinden van de draden die je zojuist hebt gestript en hebt samengevoegd.  

- knip de overige lengte van de vertinde uitbeides af zodat er 1/1.5mm over blijft om aan de Arduino Nano/Switch/LCD te solderen

**Schakelaar:** 

- Ver-tin de uiteinden van de schakelaar      
    
    <img width="30%" src="instructions-images/bedraging-switch.png">

**LCD:** 

- Ver-tin alle pads van de LCD scherm
  
    <img width="30%" src="instructions-images/bedraging-lcd.png">
    

**Arduino Nano:** 

- Ver-tin de pads van de Arduino Nano, zodat we hier later gemakkelijk de bedraging/led aan kunnen solderen:
  <img width="50%" src="instructions-images/solder-verting-nano.png">  

  - 5v
  - GND
  - D2
  - D3
  - D4
  - D5
  - D6
  - ICSP -> 5v
  - ICSP -> GND

---

## **Bedrading Solderen aan de Arduino Nano:** 

Stapsgewijs gaan wij de draden solderen. Hier alvast een overzicht van het circuit, daarna een stap voor stap uitleg.

<img width="45%" src="instructions-images/circuit.png">
<!-- align="right"  -->

1. **LED WD2812:**

    |               |     |      |      |      |                                      |
    | ------------- | --- | ---- | ---- | ---- | ------------------------------------ |
    | LED pin (+)   |     | \-\> |      | \-\> | 5v op de Arduino Nano \*(ICSP pins)  |
    | LED pin (-)   |     | \-\> |      | \-\> | GND op de Arduino Nano \*(ICSP pins) |
    | LED pin (dio) |     | \-\> | Geel | \-\> | D2 op de Arduino Nano                |
                
2. **Arcade Schakelaar + LED:**  

    |               |     |      |      |      |                                      |
    | ------------- | --- | ---- | ---- | ---- | ------------------------------------ |
    | Scakelaar (-) |     | \-\> |      | \-\> | LED (-)
    | LED (-)       |     | \-\> | Zwart| \-\> | GND op de Arduino Nano  
    | Scakelaar (+) |     | \-\> | Rood | \-\> | D3 op de Arduino Nano  
    | LED (+)       |     | \-\> | Rood | \-\> | D4 op de Arduino Nano  
    
3. **LCD:**

    |           |     |      |       |      |                        |
    | --------- | --- | ---- | ----- | ---- | ---------------------- |
    | LCD (+)   |     | \-\> | Rood  | \-\> | 5V op de Arduino Nano  |
    | LCD (-)   |     | \-\> | Zwart | \-\> | GND op de Arduino Nano |
    | LCD (CLK) |     | \-\> | Groen | \-\> | D5 op de Arduino Nano  |
    | LCD (DIO) |     | \-\> | Geel  | \-\> | D6 op de Arduino Nano  |
        

### **Stap 0:**

- Voordat je begint met solderen, zorg ervoor dat je de onderdelen als volgt neerlegt. Dit zodat het inelkaar zetten straks gemakkelijker gaat:

    <!-- <img width="50%" src="instructions-images/soldering-positie-lcd-vs-bodem.png"> -->
    <img width="48%" src="instructions-images/soldering-positie-lcd-vs-bodem-switch.png">
    <img width="25%" src="instructions-images/soldering-positie-lcd-vs-bodem-switch2.png">

### **Stap 1: Zwart GND -> Schakelaar -> LED**
- Soldeer de losse `korte` uiteinde van de `combineerde zwarte` draad op de schakelaar en led.

### **Stap 2:**    
- De `gecombineerde kant` van de zwarte draad, Soldeer deze aan de **GND** pin van de Arduino Nano.

### **Stap 3:**

- Soldeer de rode draad (40mm) aan **D2** pin van de Arduino Nano. 

### **Stap 4:**

 - Soldeer de andere uiteinde aan de WS2812 LED + 

    ps. (zorg dat deze kabel onder de zwarten door gaat)

### **Stap 4:**

-  Soldeer de rode draad (80mm) aan **D3** pin van de Arduino Nano.
    
    -> schakelaar

### **Stap 5:**

-  Soldeer de rode draad (80mm) aan **D4** pin van de Arduino Nano.

    -> Button LED +

### **Stap 6:**

-  Soldeer de rode draad aan **5v** pin van de Arduino Nano.
    -> **LCD VCC**

-  Soldeer de gele draad aan **D6** pin van de Arduino Nano.
    -> **LCD DIO**

-  Soldeer de groene draad aan **D5** pin van de Arduino Nano.
    -> **LCD CLK**

-  Soldeer de losse uiteinde van de combineerde `lange` zwarte draad op de **LCD (GND)**.
    



---

## **Arduino Nano Pinnen Solderen:**  


- Soldeer de Arduino Nano vast aan de pinnen die je in stap 2 hebt geplaatst. Dit is alleen zodat de Arduino Nano blijft zitten in de box. 1 van de 2 pennen is voldoende om dit resultaat te krijgen.

  - Let goed op dat je de juiste gaten gebruikt; je dient de buitenste twee soldeergaten aan de hoeken van de Arduino Nano te gebruiken voor een correcte en stevige verbinding.

  ** uitzondering voor de Arduino nano, die extra pinnen hebben. Hierdoor zal deze de één na laaste pinnen bevatten aan de niet usb kant.

  <img width="75%" src="instructions-images/solderen-07.png">  

## **LED Solderen aan de Arduino Nano:** 
  
  <img align="right" width="10%" src="instructions-images/led-circuit.png">

  - Plaats de LED op zijn plek. (platte zijde zit aan de rechterkant, in de foto)

  - Soldeer de (-) aan de **GND** pin van de Arduino Nano. \*(ICSP pins)  
      
  - Soldeer de (+) aan pin **5V** van de Arduino Nano. \*(ICSP pins)  
      
  - Soldeer de rode draad die je eerder op **D2** van de Arduino Nano hebt gesoldeerd, vast aan de (data) pin van de LED.

  
    <img width="75%" src="instructions-images/solderen-08.png">


## **PowerOn** 

Alles klaar? Laat iemand van de Makerspace je soldeerwerk controleren, waar gezamenlijk een check wordt gedaan door hem aan te sluiten op stroom.



# **Montage**: 

- Plaats de voorzijde in/aan de bodemplaat
    
    - houdt deze tijdelijk vast en ga verder met de volgende stap

        <img width="25%" src="instructions-images/montage-voorkant.png">
        
- Plaats de zijkant

  - `optioneel`: plaats het event logo in de zijnkant

    <img width="25%" src="instructions-images/montage-zijkant-eventlogo.png">     

  - Schroef deze vast aan de voorkant, met 2 boutjes

    <img width="25%" src="instructions-images/montage-zijkant.png">
    <img width="25%" src="instructions-images/montage-zijkant-bouten.png">

- Plaats de andere zijkant 

  - Schroef deze vast aan de voorkant, met 2 boutjes

    <img width="27.2%" src="instructions-images/montage-zijkant2.png">
    <img width="25%" src="instructions-images/montage-zijkant2-bouten.png">

- Plaats de bovenplaat

    - Draai nu de schakelaar & led gedeelte terug in de knop houder. Letop de positie van de schakelaar, deze heeft zijn contacten richting de achterkant.

        <img width="25%" src="instructions-images/montage-arcadeknop.png">

    - Test de knop, of je de schakelaar hoort/voelt wanneer de knop indrukt.

    - Schroef vast met 4 boutjes

        <img width="26.8%" src="instructions-images/montage-top.png">
        <img width="25%" src="instructions-images/montage-top-bouten.png">

- Plaats achterplaat, let op de passing van de usb aansluiting en het gat in de achterplaat.

  - Schroef vast met 4 bouten.

    <img width="25%" src="instructions-images/montage-achterkant.png">
    <img width="27.5%" src="instructions-images/montage-achterkant-bouten.png">
    

**Klaar\! Veel plezier \!**

# Code Uploaden:

https://kunstgraveren.github.io/

