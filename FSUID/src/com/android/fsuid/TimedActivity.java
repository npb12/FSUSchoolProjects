package com.android.fsuid;

import android.os.Bundle;

import android.view.ViewGroup.LayoutParams;
import android.os.CountDownTimer;
import android.app.Activity;
import android.content.Intent;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

/*
 * 
 * Activity for timed game
 */
public class TimedActivity extends Activity{
	
	private TextView timer, Games, Numdrawn, Touched, Score;
	
	private Button restart;
	
	private int touches = 0;
	private int gameCount = 0;
	private int matchthis;
	private boolean win = true;
	private boolean timeleft = true;

	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_timed);
		
		LayoutInflater inflater = getLayoutInflater();
	    View view = inflater.inflate(R.layout.toast,
	                                   (ViewGroup) findViewById(R.id.relativeLayout1));
         
	    /*
	     * 
	     * Setting toast images
	     * 
	     */
	    final Toast toast = new Toast(this);
	    toast.setView(view);
	    
	    LayoutInflater inflater2 = getLayoutInflater();
	    View view2 = inflater2.inflate(R.layout.toast2,
                (ViewGroup) findViewById(R.id.relativeLayout2));

final Toast toast2 = new Toast(this);
toast2.setView(view2);
	    
	  


		
		 restart = (Button) findViewById(R.id.newGameBtn);

		
		   LinearLayout myLayout = 
                   (LinearLayout)  
                       findViewById(R.id.LinearLayout2);
		   
		   matchthis = Choice();
		   timer = (TextView)findViewById(R.id.random);
		   Games = (TextView)findViewById(R.id.games);
		   Numdrawn = (TextView)findViewById(R.id.numdrawn);
		   Touched = (TextView)findViewById(R.id.touched);
		   Numdrawn.setText("Number Drawn : " + Integer.toString(matchthis));
		   timer();
		   		
        
		   /*
		    * 
		    * multi-touch on touch listener
		    * only counts  Action_up events
		    */
            myLayout.setOnTouchListener(
        		new LinearLayout.OnTouchListener() {
        			public boolean onTouch(View v, 
					    MotionEvent m) {
        			     int pointerCount = m.getPointerCount();
        			     // int pointerId = m.getPointerId(0);
        			     if(touches < pointerCount)
        			     {
        			       touches = pointerCount;
        			     }
        			     if(m.getAction() == MotionEvent.ACTION_UP)
        			     {
        			        GetAmount(touches);
        			        if(match(touches, matchthis) && timeleft)
        			        {
        			        	win = true;
            			        gameCount++;
            			        toast.show();
        			        }
        			        else
        			        {
        			        	gameCount = 0;
        			        	toast2.show();
        			        }
        			            Games(gameCount);
        			        matchthis = Choice();
        			        touches = 0;
        			        //win = true
        			        //else 
        			        //win = false
        			        matchit(matchthis);
        			        //ouput message that a new game is being started
                            
        			     }
        			    return true;
        			}
        			
        		}
        		
               );
		       
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	/*
	 * setting textviews
	 * 
	 */
	public void GetAmount(int n)
	{
		Touched.setText("Fingers Counted : " + Integer.toString(n));
	}
	
	public void Games(int n)
	{
		Games.setText("Games Won : " + Integer.toString(n));
	}
	
	public void matchit(int n)
	{
		Numdrawn.setText("Number Drawn : " + Integer.toString(n));
	}
	
	//		int i = Choice();
	
	public int Choice()
	{
		Random randomGenerator = new Random();
		int choice = randomGenerator.nextInt(5) + 1;
		
		return choice;
	}
	
	public boolean match(int user,int rand)
	{
		
		if(user == rand)
			return true;
		else 
			return false;
		
	}
	
	public void timer()
	{
		
		new CountDownTimer(31000, 1000) {       
			   public void onTick(long millisUntilFinished) {   
			   timeleft = true;
			   timer.setText("Time remaining: " + millisUntilFinished / 1000);      
			}       

			public void onFinish() {         
			   timer.setText("Times Up!");
			   timeleft = false;
			   launchPopup();
			}
			}.start(); 
		
	}
	

	/*
	 * 
	 * start new game
	 */
	public void newGame(View view) 
	{
		Intent intent = getIntent();
		finish();
		startActivity(intent);

		
	}
	
	
	/*
	 * 
	 * pop window at end of game
	 */
	public void launchPopup()
	{
	    LayoutInflater layoutInflater 
	    = (LayoutInflater)getBaseContext()
	     .getSystemService(LAYOUT_INFLATER_SERVICE);
//	    Score.setText(Integer.toString(gameCount));
	   View popupView = layoutInflater.inflate(R.layout.popup, null);  
	            final PopupWindow popupWindow = new PopupWindow(
	              popupView, 
	              LayoutParams.WRAP_CONTENT,  
	                    LayoutParams.WRAP_CONTENT);
	            
	            
	            popupWindow.showAsDropDown(popupView, 170, 550);
	            Score = (TextView) popupWindow.getContentView().
	                    findViewById(R.id.score);
	            Score.setText(Integer.toString(gameCount));
	            Button btnDismiss = (Button)popupView.findViewById(R.id.dismiss);
	            btnDismiss.setOnClickListener(new Button.OnClickListener(){

	    @Override
	    public void onClick(View v) {
	     // TODO Auto-generated method stub
	     popupWindow.dismiss();
	    }});
		
	}
	

	

}


