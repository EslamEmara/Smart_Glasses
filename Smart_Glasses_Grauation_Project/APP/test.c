/*
bool SWIPE_RIGHT(void)
{
	bool swipe = false; // Tracks if conditions are being met
	unsigned long startTime = millis();

	// LEFT TOUCH CONDITION
	while ((millis() - startTime) < 100)
	{
		if (CAP_isLeftTouched() == 1)
		{
			swipe = true;
			while (CAP_isLeftTouched() == 1)
			;  // Wait for user to remove their finger
			break; // Break out of loop
		}
	}

	// Return if left not touched
	if (swipe == false)
	return false;

	startTime = millis(); // Reset start time
	swipe = false;        // Reset check statement

	// MIDDLE TOUCH CONDITION
	while ((millis() - startTime) < 100)
	{
		if (CAP_isMiddleTouched() == 1)
		{
			swipe = true;
			while (CAP_isMiddleTouched() == true)
			;  // Wait for user to remove their finger
			break; // Break out of loop
		}
	}

	// Return if middle not touched
	if (swipe == false)
	{
		return false;
	}

	startTime = millis(); // Reset start time
	swipe = false;        // Reset check statement

	// RIGHT TOUCH CONDITION
	while ((millis() - startTime) < 100)
	{
		if (CAP_isRightTouched() == 1)
		{
			return true;
		}
	}

	return false;
}

*/