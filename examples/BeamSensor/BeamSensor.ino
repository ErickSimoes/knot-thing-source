/*
 * Copyright (c) 2016, CESAR.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 *
 */

#include <KNoTThing.h>

#define BEAM_SENSOR_1_ID      1
#define BEAM_SENSOR_1_NAME    "Beam Sensor 1"
#define BEAM_SENSOR_1_PIN     3

#define BEAM_SENSOR_2_ID      2
#define BEAM_SENSOR_2_NAME    "Beam Sensor 2"
#define BEAM_SENSOR_2_PIN     5

KNoTThing thing;

static int beam_read_1(int32_t *val, int32_t *multiplier)
{
  *val = digitalRead(BEAM_SENSOR_1_PIN);

  return 0;
}

static int beam_read_2(int32_t *val, int32_t *multiplier)
{
  *val = digitalRead(BEAM_SENSOR_2_PIN);

  return 0;
}

void setup()
{
  Serial.begin(9600);

  pinMode(BEAM_SENSOR_1_PIN, INPUT);
  pinMode(BEAM_SENSOR_2_PIN, INPUT);

  thing.init("KNoTThing Beam Sensor Example");

  thing.registerBoolData(BEAM_SENSOR_1_NAME, BEAM_SENSOR_1_ID,
    KNOT_TYPE_ID_PRESENCE, KNOT_UNIT_NOT_APPLICABLE, beam_read_1, NULL);

  thing.registerBoolData(BEAM_SENSOR_2_NAME, BEAM_SENSOR_2_ID,
    KNOT_TYPE_ID_PRESENCE, KNOT_UNIT_NOT_APPLICABLE, beam_read_2, NULL);

  Serial.println("Beam Sensor KNoT Demo");
}


void loop()
{
  thing.run();
}
