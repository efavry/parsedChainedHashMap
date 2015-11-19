#ifndef __RECORD__
#define __RECORD__


typedef struct record{
  char *unic_id; /*key*/
  int size_unic_id;
  char *id;
  int size_id;
  int hour;
  int minute;
  int second;
  int id_cell;
  char *techno_used; /*aloca a 20 ?*/
  int size_techno;
  float longit;
  float lati;
} Record;

Record RecordNew();

Record RecordCopy(Record tcpy);

void RecordFree(Record rec);
/*set the id by memcpy*/
/*ATENTION !!!! VOIRE CODSE*/
Record RecordSetUnicId(Record rec);

/*set the id by memcpy*/
Record RecordSetId(Record rec, char *id, int size);

/*read the time and send it to the correct function*/
Record RecordSetTime(Record rec, char *time);

/*set the hour of the record*/
Record RecordSetHour(Record rec, char *h);

/*set the minute of the record*/
Record RecordSetMinute(Record rec, char *m);

/*set the second of the record*/
Record RecordSetSecond(Record rec, char *s);

/*set the id cell of the record*/
Record RecordSetIdCell(Record rec, char *id_cell);

/*set the techno_used field of the record*/
Record RecordSetTechnoUsed(Record rec, char *techno_used,int size);

/*set the Longitude of the record*/
Record RecordSetLongitude(Record rec, char *longit);

/*set the Latitude of the record*/
Record RecordSetLatitude(Record rec, char *lati);

/*Show the record*/
void RecordShow(Record rec);

int RecordCompare(Record rec1, Record rec2);

/*Compare twor record return 1 if equals*/
int RecordPureEquals(Record rec1, Record rec2);
#endif
