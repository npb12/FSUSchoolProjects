package com.android.fsuid;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;

public class GameActivity extends Activity {
	
	

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_game);
  }

  @Override
  public boolean onCreateOptionsMenu(Menu menu) {
    getMenuInflater().inflate(R.menu.main, menu);
    return true;
  }

} 