package com.android.fsuid;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;


/*
 * 
 * "Home page" activity
 */
public class MainActivity extends Activity {

	private Button Button1, Button2;
	//private TextView turn;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
        
      Button1 = (Button) findViewById(R.id.buttons);
      Button2 = (Button) findViewById(R.id.buttons2);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	/*
	 * 
	 * start new activities on button clicks
	 */
	public void sendMessage(View view) 
	{
	    Intent intent = new Intent(com.android.fsuid.MainActivity.this, com.android.fsuid.GameActivity.class);
	    startActivity(intent);
	}
	
	public void sendMessage2(View view) 
	{
	    Intent intent = new Intent(com.android.fsuid.MainActivity.this, com.android.fsuid.TimedActivity.class);
	    startActivity(intent);
	}

}

