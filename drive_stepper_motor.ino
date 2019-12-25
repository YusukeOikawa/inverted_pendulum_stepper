void drive_stepper_motor(int dir, int speed_width)
{
  frq = speed_width / (float)max_speed * max_frq;
  digitalWrite(r_dir, dir);
  digitalWrite(l_dir, --dir);
  // TOP値指定
  ICR1 = (unsigned int)(1000000 / frq);
  
  // Duty比指定
  OCR1A = (unsigned int)(1000000 / frq * duty);
  OCR1B = (unsigned int)(1000000 / frq * duty);
}
