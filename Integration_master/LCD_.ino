void lcd_print(int r0,String s0,int r1,String s1){
    lcd.clear();
    lcd.setCursor(r0,0); 
    lcd.print(s0); 
    lcd.setCursor(r1,1); 
    lcd.print(s1); 
}
