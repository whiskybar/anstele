<?php
/* Author: Ida Wellner */

$labels = array();
$labels['filters'] = 'Filter';
$labels['managefilters'] = 'Hantera filter';
$labels['filtername'] = 'Filternamn';
$labels['disablerule'] = 'Inaktivera regel';
$labels['disabled'] = 'Inaktiverad';
$labels['newfilter'] = 'Nytt filter';
$labels['moveup'] = 'Flytta uppåt';
$labels['movedown'] = 'Flytta nedåt';
$labels['filterallof'] = 'matcha samtliga av följande regler';
$labels['filteranyof'] = 'matcha en av följande regler';
$labels['filterany'] = 'alla meddelanden';
$labels['filtercontains'] = 'innehåller';
$labels['filternotcontains'] = 'inte innehåller';
$labels['filteris'] = 'är';
$labels['filterisnot'] = 'inte är';
$labels['filterexists'] = 'existerar';
$labels['filternotexists'] = 'inte existerar';
$labels['filterregex'] = 'matchar följande reguljära uttryck';
$labels['filternotregex'] = 'inte matchar följande reguljära uttryck';
$labels['filterunder'] = 'är mindre än';
$labels['filterover'] = 'är större än';
$labels['filteradvoptions'] = 'fler inställningar...';
$labels['spamtest'] = 'Spamklassning';
$labels['operator'] = 'Operator';
$labels['comparator'] = 'Typ av matchning';
$labels['isgreaterthan'] = 'är större än';
$labels['isgreaterthanequal'] = 'är större än eller lika med';
$labels['islessthan'] = 'är mindre än';
$labels['islessthanequal'] = 'är mindre än eller lika med';
$labels['equals'] = 'är lika med';
$labels['notequals'] = 'är inte lika med';
$labels['countisgreaterthan'] = 'antal är större än';
$labels['countisgreaterthanequal'] = 'antal är större än eller lika med';
$labels['countislessthan'] = 'antal är mindre än';
$labels['countislessthanequal'] = 'antal är mindre än eller lika med';
$labels['countequals'] = 'antal är lika med';
$labels['countnotequals'] = 'antal är inte lika med';
$labels['valueisgreaterthan'] = 'värdet är större än';
$labels['valueisgreaterthanequal'] = 'värdet är större än eller lika med';
$labels['valueislessthan'] = 'värdet är mindre än';
$labels['valueislessthanequal'] = 'värdet är mindre än eller lika med';
$labels['valueequals'] = 'värdet är lika med';
$labels['valuenotequals'] = 'värdet är inte lika med';
$labels['userpart'] = 'användare är lika med';
$labels['notuserpart'] = 'användare är inte lika med';
$labels['detailpart'] = 'klartextnamn är lika med';
$labels['notdetailpart'] = 'klartextnamn är inte lika med';
$labels['domainpart'] = 'domän är lika med';
$labels['notdomainpart'] = 'domän är inte lika med';
$labels['teststring'] = 'Matcha mot';
$labels['messagemoveto'] = 'Flytta meddelande till';
$labels['messageredirect'] = 'Omdirigera meddelande till';
$labels['messageimapflags'] = 'Markera meddelande som';
$labels['messagereject'] = 'Avvisa med meddelande';
$labels['messagevacation'] = 'Frånvarobesked';
$labels['messagekeep'] = 'Behåll meddelandet';
$labels['messagediscard'] = 'Kasta meddelandet';
$labels['messagenotify'] = 'Skicka notifiering';
$labels['messagestop'] = 'Sluta behandla filter';
$labels['messagehelp'] = 'Vad är detta?';
$labels['sieveorigsubj'] = 'Lägg till orginalmeddelandets ämnesrad i svaret';
$labels['sievevachandle'] = 'Id';
$labels['method'] = 'Metod';
$labels['options'] = 'Options';
$labels['messagesrules'] = 'Filterregler';
$labels['messagesactions'] = 'Filteråtgärder';
$labels['sieveto'] = 'Alias';
$labels['sievefrom'] = 'Från';
$labels['flag'] = 'Prioritet';
$labels['importancen'] = 'Ingen';
$labels['importance1'] = 'Hög';
$labels['importance2'] = 'Normal';
$labels['importance3'] = 'Låg';
$labels['flagread'] = 'Läst';
$labels['flagdeleted'] = 'Borttaget';
$labels['flaganswered'] = 'Besvarat';
$labels['flagdraft'] = 'Utkast';
$labels['flagflagged'] = 'Flaggat';
$labels['addsieverule'] = 'Lägg till ytterligare regel under denna';
$labels['addsieveact'] = 'Lägg till ytterligare åtgärd under denna';
$labels['deletesieverule'] = 'Ta bort denna regel';
$labels['deletesieveact'] = 'Ta bort denna åtgärd';
$labels['envelopefrom'] = 'Kuvertavsändare';
$labels['envelopeto'] = 'Kuvertmottagare';
$labels['otherheader'] = 'Annat brevhuvud';
$labels['period'] = 'Dagar';
$labels['message'] = 'Meddelande';
$labels['sieveruleheaders'] = 'Se exempel på andra brevhuvuden';
$labels['examplefilters'] = 'Exempelfilter';
$labels['importfilters'] = 'Importera filter';
$labels['usedefaultfilter'] = 'Använd standardfilter';
$labels['importfilter'] = 'Importera filter';
$labels['adveditor'] = 'Avancerad editor';
$labels['messageredirectcopy'] = 'Skicka en kopia till';
$labels['messagecopyto'] = 'Kopiera meddelandet till';
$labels['body'] = 'Meddelandetext';
$labels['auto'] = 'Auto';
$labels['raw'] = 'Raw';
$labels['text'] = 'Text';
$labels['other'] = 'Annat';
$labels['bodycontentpart'] = 'Innehållsdel';
$labels['notchecked'] = 'inte kontrollerat';
$labels['spamlevelisgreaterthanequal'] = 'är större än eller lika med';
$labels['spamlevelislessthanequal'] = 'är mindre än eller lika med';
$labels['spamlevelequals'] = 'är lika med';
$labels['i;ascii-casemap'] = 'ej skiftlägeskänslig strängmatchning';
$labels['i;octet'] = 'exakt strängmatchning';
$labels['i;ascii-numeric'] = 'numerisk matchning';

$messages = array();
$messages['nosieverules'] = 'Inga filter funna.';
$messages['filterdeleteconfirm'] = 'Är du säker på att du vill ta bort det här filtret?';
$messages['ruledeleteconfirm'] = 'Är du säker på att du vill radera den här regeln?';
$messages['actiondeleteconfirm'] = 'Är du säker på att du vill radera den här åtgärden?';
$messages['filterunknownerror'] = 'Okänt serverfel';
$messages['filterconnerror'] = 'Kan ej kontakta sieve-servern';
$messages['filterdeleteerror'] = 'Kan ej ta bort filtret. Ett serverfel inträffade.';
$messages['filterdeleted'] = 'Filtret har tagits bort';
$messages['filtersaved'] = 'Filret har sparats';
$messages['filtersaveerror'] = 'Kan inte spara filtret. Ett serverfel inträffade.';
$messages['vacperiodexp'] = 'Frånvaromeddelandet kommer endast att skickas en gång till samma användare under det antal dagar som anges ovan, oavsett hur många gånger den personen mailar dig.<br /> <br />Exempel: Om Joe mailar dig på måndag och antalet dagar är 7 kommer han att få ett frånvaromeddelande på måndag, men sedan får han inget nytt förrän nästa måndag oavsett hur många gånger han mailar dig under veckan.';
$messages['vachandleexp'] = 'Ett id kan använndas för att länka samman flera frånvaromeddelanden. När ett frånvaromeddelande med detta id har skickats kommer inga fler att frånvaromeddelanden med samma id att skickas under perioden.';
$messages['vactoexp'] = 'Frånvaromeddelandet skickas enbart till din huvudsakliga adress + de adresser du valt i listan ovan. Har du fler mottagaradresser du vill kunna välja bland måste du först lägga till dessa under Profiler.';
$messages['norulename'] = 'Fyll i ett namn på detta filter.';
$messages['ruleexists'] = 'Ett filter med det valda namnet finns redan. Vänligen fyll i ett annat namn.';
$messages['noheader'] = 'Fyll i namnet på brevhuvudet';
$messages['headerbadchars'] = 'Fel: Brevhuvudet innehåller otillåtna tecken';
$messages['noheadervalue'] = 'Fyll i ett värde som brevhuvudet ska testas mot';
$messages['sizewrongformat'] = 'Fel: Meddelandestorlek måste anges i siffror';
$messages['noredirect'] = 'Fyll i en e-postadress att omdirigera meddelanden till';
$messages['redirectaddresserror'] = 'Fel: e-postadressen har inte giltigt format';
$messages['noreject'] = 'Fyll i ett meddelande som ska skickas med brev som avvisas';
$messages['vacnoperiod'] = 'Fyll i antalet dagar för den period under vilken meddelandet inte kommer att skickas på nytt till samma person';
$messages['vacperiodwrongformat'] = 'Fel: Antalet dagar måste vara ett tal större än eller lika med 1';
$messages['vacnomsg'] = 'Fyll i text som ska skickas i frånvaromeddelandet';
$messages['notifynomethod'] = 'Fyll i med vilken metod notifieringen ska skickas';
$messages['notifynomsg'] = 'Fyll i en notifieringstext';
$messages['sieveruleexp'] = 'Definiera en eller flera regler som varje meddelande kommer att testas mot. Filter körs i den ordning de listas till vänster.';
$messages['sieveactexp'] = 'Välj bland alternativen nedan. Dessa åtgärder kommer att utföras varje gång ett meddelande matchar reglerna ovan.';
$messages['sieveheadershlp'] = 'Detta är några exempel på andra brevhuvudet som filtren kan testa. Välj ett brevhuvud för att lägga till det till regeln eller fyll i ett eget brevhuvud.';
$messages['movingfilter'] = 'Flyttar filter...';
$messages['noexistingfilters'] = 'Hittar inga existerande filter!';
$messages['importdefault'] = '<b>Använd standardfilter:</b> Det finns en uppsättning standardfilter tillgängliga. Skulle du vilja använda dem?';
$messages['importother'] = '<b>Importera filter:</b> En annan uppsättning filter från %s har upptäckts. Skulle du vilja importera dem till din nuvarande filteruppsättning?';
$messages['switchtoadveditor'] = 'Med den avancerade editorn kan du redigera din filterfil direkt. Ändringar gjorda där kan gå förlorade om du senare redigerar dina filter via den vanliga filterredigeringen. Vill du fortsätta?';
$messages['filterimported'] = 'Importen av filter lyckades';
$messages['filterimporterror'] = 'Importen av filter misslyckades. Ett serverfel uppstod.';
$messages['notifyinvalidmethod'] = 'Den angivna metoden har inte ett giltigt format, det måste vara en URI. Exempel: `mailto:alert@example.com`.';
$messages['nobodycontentpart'] = 'Fyll i vilken del av innehållet som ska testas';
$messages['badoperator'] = 'Den valda operatorn kan inte användas i den här regeln';
$messages['filteractionerror'] = 'Den valda åtgärden stöds inte av servern';
$messages['filtermissingerror'] = 'Kan inte hitta den önskade regeln';
$messages['contentpartexp'] = 'Fyll i MIME-typ eller specifik del av meddelandet som ska testas. Exempel: `message/rfc822`, `text/html`, `audio/mp3`';

?>