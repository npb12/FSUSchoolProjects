package com.android.assignment4;

import java.io.IOException;

import com.android.assignment4.R;


import android.media.MediaPlayer;
import android.os.Bundle;
import android.app.Activity;
import android.content.res.AssetFileDescriptor;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {

	Button bwc, bfs, bvs, bgg, bfc, bff, bur, bstop;
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		
		bwc = (Button) findViewById(R.id.button_warchant);
		bfs = (Button) findViewById(R.id.button_fightson);
		bvs = (Button) findViewById(R.id.button_victorysong);
		bgg = (Button) findViewById(R.id.button_garnetgold);
		bfc = (Button) findViewById(R.id.button_fsucheer);
		bff = (Button) findViewById(R.id.button_4thfan);
		bur = (Button) findViewById(R.id.button_uprising);
		bstop = (Button) findViewById(R.id.button_stop);
		
		bwc.setOnClickListener(ButtonMediaListener);
		bfs.setOnClickListener(ButtonMediaListener);
		bvs.setOnClickListener(ButtonMediaListener);
		bgg.setOnClickListener(ButtonMediaListener);
		bfc.setOnClickListener(ButtonMediaListener);
		bff.setOnClickListener(ButtonMediaListener);
		bur.setOnClickListener(ButtonMediaListener);
		bstop.setOnClickListener(ButtonMediaListener);
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
    View.OnClickListener ButtonMediaListener = new OnClickListener() {

        public void onClick(View v) {
        	MediaPlayer mp = new MediaPlayer();
			int id = v.getId();
			String song = null;
			switch(id) {
				case R.id.button_warchant:
					 song = "war_chant.mp3";
					break;
				case R.id.button_fightson:
					song = "fsu_fightsong.mp3";
					break;
				case R.id.button_victorysong:
					song = "victory_song.mp3";
					break;
				case R.id.button_garnetgold:
					song = "gold_garnett.mp3";
					break;
				case R.id.button_fsucheer:
					song = "fsu_cheer.mp3";
					break;
				case R.id.button_4thfan:
					song = "4thquarter_fanfare.mp3";
					break;
				case R.id.button_uprising:
					song = "seminole_uprising.mp3";
					break;
				case R.id.button_stop:
					try { 
					       mp.stop(); 
					  } catch(Exception ex) { 
					     ex.printStackTrace(); 
					  }
             
			}
			if(id != R.id.button_stop)
			{
	        try {

	            AssetFileDescriptor afd;
	            afd = getAssets().openFd(song);
	            mp.setDataSource(afd.getFileDescriptor(),afd.getStartOffset(),afd.getLength());
	            mp.prepare();
	            mp.start();
	        } catch (IllegalStateException e) {
	            e.printStackTrace();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }
			}
        }
        
        
    };
    
    


}
