package com.android.assignment5;

import com.android.assignment5.R;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.PopupWindow;
import android.view.LayoutInflater;
import android.view.ViewGroup.LayoutParams;

import java.util.Random;

public class MainActivity extends Activity {
	
	private int playerChoice;
	private int playerScore, compScore;
	private String result, compPick;
    private int compChoice; 
    private int gameCount = 1;
    RadioButton rb1, rb2, rb3;

    
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
        
        rb1 = (RadioButton) findViewById(R.id.radio_rock);
        rb2 = (RadioButton) findViewById(R.id.radio_paper);
        rb3 = (RadioButton) findViewById(R.id.radio_scissor);
        
        
        
                                                    
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	public void onRadioButtonClicked(View view) {
	    // Is the button now checked?
	    boolean checked = ((RadioButton) view).isChecked();
	    
	    // Check which radio button was clicked
	    switch(view.getId()) {
	        case R.id.radio_paper:
	            if (checked)
	            	playerChoice = 1;
	            break;
	        case R.id.radio_rock:
	            if (checked)
	            	playerChoice = 2;
	            break;
	        case R.id.radio_scissor:
	            if (checked)
	                playerChoice = 3;
	            break;
	    }
        result();
	}
	
	public int computerChoice()
	{
		Random randomGenerator = new Random();
		int choice = randomGenerator.nextInt(3) + 1;
		
		return choice;
	}
	
    
    public void result(){
    	
    	compChoice = computerChoice();
    	if(compChoice == 1)
    	{
    		compPick = "Rock";
    	}
    	if(compChoice == 2)
    	{
    		compPick = "Paper";
    	}
    	if(compChoice == 3)
    	{
    		compPick = "Scissors";
    	}
	    switch(playerChoice) {
	    //playerChoice = rock
        case 1:
            if(compChoice == 1)
            {
            	result = "#Winning";
            }
            else if(compChoice == 2)
            {
            	result = "It's a Tie";
            }
            else if(compChoice == 3)
            {
            	result = "Soooo you lost....";
            }
            break; 
        //playerChoice = paper
        case 2:
            if(compChoice == 1)
            {
              result = "It's a Tie";
            }
            else if(compChoice == 2)
            {
            	result = "Soooo you lost....";

            }
            else if(compChoice == 3)
            {   
            	result = "#Winning";
            }
            break;
        //playerChoice = scissors
        case 3:
            if(compChoice == 1)
            {
            	result = "Soooo you lost....";
            }
            else if(compChoice == 2)
            {
            	result = "#Winning";
            }
            else if(compChoice == 3)
            {
            	result = "It's a Tie";
            }

            break;
    }
	    Toast.makeText(this, "The computer chose "+ compPick , Toast.LENGTH_SHORT).show();
	    Toast.makeText(this, result, Toast.LENGTH_SHORT).show();
	    
    if(result == "#Winning")
    {
      ++playerScore;
    }
    else if(result == "Soooo you lost....")
    {
	  ++compScore;
    }
    
    Toast.makeText(this, "Computer: " + compScore  +
    		" Player: " + playerScore, Toast.LENGTH_SHORT).show();
    
      
    if(gameCount % 10 == 0)
    {
  	    launchPopup();
    }
      ++gameCount;

    
}
	
public void launchPopup()
{
    LayoutInflater layoutInflater 
    = (LayoutInflater)getBaseContext()
     .getSystemService(LAYOUT_INFLATER_SERVICE);  
   View popupView = layoutInflater.inflate(R.layout.popup, null);  
            final PopupWindow popupWindow = new PopupWindow(
              popupView, 
              LayoutParams.WRAP_CONTENT,  
                    LayoutParams.WRAP_CONTENT);
            
            
            popupWindow.showAsDropDown(popupView, 50, 150);

            Button btnDismiss = (Button)popupView.findViewById(R.id.dismiss);
            btnDismiss.setOnClickListener(new Button.OnClickListener(){

    @Override
    public void onClick(View v) {
     // TODO Auto-generated method stub
     popupWindow.dismiss();
    }});
	
}




	
	

}
