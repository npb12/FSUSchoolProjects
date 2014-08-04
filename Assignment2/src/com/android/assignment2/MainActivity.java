package com.android.assignment2;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends Activity {
	
	private ImageView image;
	private Button Button1;
	int current = 0;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
        image = (ImageView)findViewById(R.id.imagesView);
        Button1 = (Button) findViewById(R.id.buttons);

        //Just set one Click listener for the image

        Button1.setOnClickListener(ButtonChangeImageListener);
		

	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
    View.OnClickListener ButtonChangeImageListener = new OnClickListener() {

        public void onClick(View v) {

              if (current == 0)
        	  {
        	    image.setImageResource(R.drawable.seminole);
        	    Button1.setText(R.string.showGator);
        	    current = 1;
        	  }
        	  else if (current == 1)
        	  {
        	    image.setImageResource(R.drawable.flagators);
        	    Button1.setText(R.string.showNole);
        	    current = 0;
        	  }

        }
    };
	
	

}